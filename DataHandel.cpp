#include "curl.h"
#include "date.h"
#include "equity.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include<stack>

void AllStock() {
	//stock pool. with infomation listed below.
	std::string ticker;
	std::string date;
	double surp;
	int y;
	int m;
	int d;
	std::string sec_name;
	std::string comp_sector;
	std::string comp_subsec;
	std::string addr;
	int cik_name;

	//read file
	ifstream file("wen jian ming shi shen me ni men yao gai");
	std::string line;
	//skip header
	getline(file, line);

	//parsing file
	while (getline(file, line)) {
	/* note here, we cannot use file.good() or !file.eof() because the last line's eof will be ingored.
	in order to prevent that from happending, use getline for logic, so below, we read the parsed line
	and store info accordingly. */
		std::istringstream iss(line);
		std::string token;
		//store info
		getline(iss, token, ',');
		ticker = token;

		getline(iss, token, ',');
		date = token;

		//skip estimate and actuall

		getline(iss, token, ',');
		surp = stod(token);

		getline(iss, token, ',');
		y = stoi(token);

		getline(iss, token, ',');
		m = stoi(token);

		getline(iss, token, ',');
		d = stoi(token);

		//url_generator
		std::string cur_url = url_generator(ticker, y, m, d);

		getline(iss, token, ',');
		sec_name = token;

		getline(iss, token, ',');
		comp_sector = token;

		getline(iss, token, ',');
		comp_subsec = token;

		getline(iss, token, ',');
		addr = token;

		getline(iss, token, ',');
		cik_name = stoi(token);

		//download price & calculat5e return
		map<Date, double> cur_price, cur_ret;
		Date cur_start, cur_end;
		Date cur_rep_date(y, m, d);
		price_getter(ticker, y, m, d, cur_price, cur_ret,cur_start,cur_end);
			//stock constructor with p
		Stock cur_stock(ticker, cur_start,cur_end,cur_rep_date, cur_price,cur_ret,sec_name, comp_sector.
						comp_subsec, addr, cik_name,surp);
		all_stocks.push_back(cur_stock);
	}
	//close file
	file.close();
}

//convert some month or days with single digit to two digits string starting with 0, convert other months to strings directly
std::string converter(int a) {
	std::stringstream s;
	if (a < 10) s << 0 << a;
	else s << a;
	std::string ret = s.str();
	return ret;
}

std::string url_generator(std::string stk, int year, int month, int day) {
	//"http://ichart.yahoo.com/table.csv?s=AAPL&a=00&b=1&c=2010&d=03&e=25&f=2015&g=w&ignore=.csv");
	//combine sevearl strings together
	std::stringstream ss;
	/*if report month <= 3, year before shift back one too. when month is between 4 and 10, everything is normal, we just take 
	start date as 4 months before, end date as two months later. when month > 10, year after need to move forward one*/
	if (month <= 3) 
		ss << fixed << "http://ichart.yahoo.com/table.csv?" << stk << "&a=" << converter(month + 9) << "&b=" << "28" << "&c=" << converter(year-1) << "&d=" << converter(month + 2) << "e=" << "28" << "f=" << converter(year) << "g=w&ignore=.csv";
	else if (month >= 4 && month < 10) 
		ss << fixed << "http://ichart.yahoo.com/table.csv?" << stk << "&a=" << converter(month - 3) << "&b=" << "28" << "&c=" << converter(year) << "&d=" << converter(month + 2) << "e=" << "28" << "f=" << converter(year) << "g=w&ignore=.csv";
	else if (month >= 10) 
		ss << fixed << "http://ichart.yahoo.com/table.csv?" << stk << "&a=" << converter(month - 3) << "&b=" << "28" << "&c=" << converter(year) << "&d=" << converter(month - 9) << "e=" << "28" << "f=" << converter(year + 1) << "g=w&ignore=.csv";
	std::string s = ss.str();
	return s;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void price_getter(std::string stk, int year, int month, int day, map<Date,double>& price, map<Date, double>& ret, Date start_date, Date end_date){
	std::string readBuffer;
	stack<Date> date;
	stack<double> adj;

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
		curl_easy_setopt(handle, CURLOPT_URL, url_generator(stk, year, month,day));
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

	Date target(year, month, day);

	int count_push = 0;
	int count_pop = 0;

	//string manipulation. We seperated string by EOF then take substrings of what we need. 
	std::istringstream ss(readBuffer);
	std::string token;
	getline(ss, token, '\n');
	while (getline(ss, token, '\n')) {
		std::string temp = token.substr(0, 10);
		int cur_year = stoi(temp.substr(0, 4));
		int cur_month = stoi(temp.substr(5, 6));
		int cur_day = stoi(temp.substr(8, 9));
		Date cur(cur_year, cur_month, cur_day);
		
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
			price[date.top()] = adj.top();
			date.pop();
			adj.pop();
		}
		else if (date.top() > target && count_pop < 30) {
			price[date.top()] = adj.top();
			date.pop();
			adj.pop();
			count_pop += 1;
		}
	}

	start_date = price.begin()->first;
	end_date = price.end()->first;
	// make the program stop for avoiding the console closing before we can see anything
	system("PAUSE");
	return;
}


