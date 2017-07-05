# fin-comp
fin comp final project
Hooooray!

Today is the first day of our project! --Apr 15, 2017

## Goal of this Project 
We see surprises in company's quater earning reports. Sometimes companies are doing better than they expected and sometimes they miss the expectation. This surprise factor can be considered as one sentiment signal, therefore it could cause flucutation in stock prices.
Is the effect real?
## Methodology: Bootstrapping
why? minimize the effect of noises
How? We divide the suprise factors into three groups: meet, beat (+5% to +10% depends on user's input), and miss (the opposite of beat).
We use 453 stocks to form our stock pool. After we divide them into 3 big groups by their earning surprises, we randomly select 40 stocks with replacement and calculate their Average Abnormal Return (AAR) and Cumulative Average Abnormal Return (CAAR), for N resample times, and finally take the average.
## Project Architechture
With Qt as the frame, we have three subsystem: a multithreading DataHandle (process all data extracted from Yahoo Finance and companies' constituents information from Bloomberg), Core (sample data and store calculation), ExcelDriver (connect to Excel and display all calculation and plotting result).




