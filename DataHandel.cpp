#include "curl.h"
#include "date.h"
#include "equity.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include<stack>
using namespace std;

vector<Stock>& AllStock(string filename) {
	//stock pool. with infomation listed below.
	vector<Stock> stocks(455);

	vector<string> ticker;
	vector<string> date;
	vector<string> surp;
	vector<string> y;
	vector<string> m;
	vector<string> d;
	vector<string> sec_name;
	vector<string> comp_sector;
	vector<string> comp_subsec;
	vector<string> addr;
	vector<string> cik_list;

	//read file
	ifstream file(filename);
	string line;
	//skip header
	getline(file, line);

	//parsing file
	while (getline(file, line)) {
	/* note here, we cannot use file.good() or !file.eof() because the last line's eof will be ingored.
	in order to prevent that from happending, use getline for logic, so below, we read the parsed line
	and store info accordingly. */
		istringstream iss(line);
		string token;
		//store info
		getline(iss, token, ',');
		ticker.push_back(token);

		getline(iss, token, ',');
		date.push_back(token);

		//skip estimate and actuall

		getline(iss, token, ',');
		surp.push_back(token);

		getline(iss, token, ',');
		y.push_back(token);

		getline(iss, token, ',');
		m.push_back(token);

		getline(iss, token, ',');
		d.push_back(token);

		getline(iss, token, ',');
		sec_name.push_back(token);

		getline(iss, token, ',');
		comp_sector.push_back(token);

		getline(iss, token, ',');
		comp_subsec.push_back(token);

		getline(iss, token, ',');
		addr.push_back(token);

		getline(iss, token, ',');
		cik_list.push_back(token);
	}
	//close file
	file.close();

	//initialize stock properties
	for (int i = 0;i < stocks.size();i++) {
		//company information filling
		stocks[i].ticker = ticker[i];
		stocks[i].security = sec_name[i];
		stocks[i].sector = comp_sector[i];
		stocks[i].sub_industry = comp_subsec[i];
		stocks[i].address = addr[i];
		stocks[i].cik = stoi(cik_list[i]);
		//date info filling
		stocks[i].rep_date.SetYear(stoi(y[i]));
		stocks[i].rep_date.SetMonth(stoi(m[i]));
		stocks[i].rep_date.SetDay(stoi(d[i]));
		//numerical filling
		stocks[i].surprise = stod(surp[i]);
	}
	return stocks;
}

//convert some month or days with single digit to two digits string starting with 0, convert other months to strings directly
string converter(int a) {
	stringstream s;
	if (a < 10) s << 0 << a;
	else s << a;
	string ret = s.str();
	return ret;
}

string web_generator(Stock stk) {
	//"http://ichart.yahoo.com/table.csv?s=AAPL&a=00&b=1&c=2010&d=03&e=25&f=2015&g=w&ignore=.csv");
	//combine sevearl strings together
	stringstream ss;
	static int stk_y = stk.GetRepDate.GetYear;
	static int stk_m = stk.GetRepDate.GetMonth;
	static int stk_d = stk.GetRepDate.GetDay;
	/*if report month <= 3, year before shift back one too. when month is between 4 and 10, everything is normal, we just take 
	start date as 4 months before, end date as two months later. when month > 10, year after need to move forward one*/
	if (stk_m <= 3) 
		ss << fixed << "http://ichart.yahoo.com/table.csv?" << stk.ticker << "&a=" << converter(stk_m + 9) << "&b=" << "28" << "&c=" << converter(stk_y-1) << "&d=" << converter(stk_m + 2) << "e=" << "28" << "f=" << converter(stk_y) << "g=w&ignore=.csv";
	else if (4 <= stk_m < 10) 
		ss << fixed << "http://ichart.yahoo.com/table.csv?" << stk.ticker << "&a=" << converter(stk_m - 3) << "&b=" << "28" << "&c=" << converter(stk_y) << "&d=" << converter(stk_m + 2) << "e=" << "28" << "f=" << converter(stk_y) << "g=w&ignore=.csv";
	else if (stk_m >= 10) 
		ss << fixed << "http://ichart.yahoo.com/table.csv?" << stk.ticker << "&a=" << converter(stk_m - 3) << "&b=" << "28" << "&c=" << converter(stk_y) << "&d=" << converter(stk_m - 9) << "e=" << "28" << "f=" << converter(stk_y + 1) << "g=w&ignore=.csv";
	string s = ss.str();
	return s;
}


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

map<Date,double>& price_getter(Stock stk){
	string readBuffer;
	stack<Date> date;
	stack<double> adj;
	map<Date, double> ret;
		// declaration of an object CURL, initialization, set result variable.
	CURL *handle;
	CURLcode result;
	curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();
	//if handle is good, perform
	if (handle)
	{
		//use web_generator to generate stock info
		//ATTENTION!! possible errors
		curl_easy_setopt(handle, CURLOPT_URL, web_generator(stk));
		//if not successful, follow redirection
		curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
		//important notice: this line is to skip certificate problem. if not added, perform cannot be run
		curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, FALSE);
		//use the following two lines for writing data to a string. note: this string takes everything
		curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(handle, CURLOPT_WRITEDATA, &readBuffer);
		result = curl_easy_perform(handle);
		// Check for errors 
		if (result != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
			//print 1;
		}
	}
	else
	{
		fprintf(stderr, "Curl init failed!\n");
		//return 1;
	}
	//clean up
	curl_easy_cleanup(handle);
	curl_global_cleanup();

	Date target = stk.GetRepDate();
	int count_push = 0;
	int count_pop = 0;
	//string manipulation. We seperated string by EOF then take substrings of what we need. 
	istringstream ss(readBuffer);
	string token;
	getline(ss, token, '\n');
	while (getline(ss, token, '\n')) {
		Date cur;
		string temp = token.substr(0, 10);
		cur.SetYear(stoi(temp.substr(0, 4)));
		cur.SetMonth(stoi(temp.substr(5, 6)));
		cur.SetYear(stoi(temp.substr(8, 9)));
		if(cur > target || cur == target){
			date.push(cur);
			adj.push(stod(token.substr(token.find_last_of(',') + 1, token.back())));
		}
		else if(cur < target && count_push < 60) {
			date.push(cur);
			adj.push(stod(token.substr(token.find_last_of(',') + 1, token.back())));
			count_push += 1;
		}
	}

	//fill up map<Date, double> which represent date and price.
	while (!date.empty()) {
		if (date.top() < target || date.top() == target) {
			ret[date.top()] = adj.top();
			date.pop();
			adj.pop();
		}
		else if (date.top() > target && count_pop < 30) {
			ret[date.top()] = adj.top();
			date.pop();
			adj.pop();
			count_pop += 1;
		}
	}
	// make the program stop for avoiding the console closing before we can see anything
	system("PAUSE");
	//return 0;
}


