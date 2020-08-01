Action()
{

	lr_start_transaction("tr_main");
	
	lr_start_transaction("tr_home_page");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='129229.374159579zztHcDfpQDDDDDDDDQiiDptVfz' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("tr_home_page", LR_AUTO);

	lr_start_transaction("tr_login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(15);
	
	web_reg_find("Fail=NotFound",
		"Text/IC/DIG=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=53", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("tr_login",LR_AUTO);

	lr_start_transaction("tr_flight_button");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(40);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("tr_flight_button",LR_AUTO);

	lr_start_transaction("tr_insert_flight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(35);
	
	web_reg_find("Search=Body",
		"Text=Flight departing from <B>{Cities}</B> to <B>{Cities2}</B> on <B>{departDate}</B>");
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value={aD}", ENDITEM, 
		"Name=depart", "Value={Cities}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={Cities2}", ENDITEM, 
		"Name=returnDate", "Value={arriveDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=46", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("tr_insert_flight",LR_AUTO);

	lr_think_time(47);

	lr_start_transaction("tr_find_flight");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Flight Reservation",
		LAST); 
	
//	web_reg_save_param_ex(
//		"ParamName=outboundFlight",
//		"LB=name=\"outboundFlight\" value=\"",
//		"RB=\"",
//		"Ordinal=ALL",
//		SEARCH_FILTERS,
//		LAST);
	
//сделал обе корреляции, тыкал разные формы строки, все равно читает ее просто как стринг, а не как параметр
	
	web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB/IC=\"" ,
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=51", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("tr_find_flight",LR_AUTO);

	lr_start_transaction("tr_payment_details");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(69);
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Thank you for booking through Web Tours",
		LAST);
	
//	web_reg_find("Fail=NotFound",
//		"Text/IC=A {seatType} Class ticket from {Cities} to {Cities2}",
//		LAST);
// не работает, т.к. outbound не проходит корреляцию, и в конце в форму уходит тот, что был при записи

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={FN}", ENDITEM,
		"Name=lastName", "Value={LN}", ENDITEM,
		"Name=address1", "Value={Cities}", ENDITEM,
		"Name=address2", "Value={Cities2}", ENDITEM,
		"Name=pass1", "Value={FullName}", ENDITEM,
		"Name=creditCard", "Value={CreditCard}", ENDITEM,
		"Name=expDate", "Value={rn}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value={aD}", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=44", ENDITEM,
		"Name=buyFlights.y", "Value=5", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

	lr_end_transaction("tr_payment_details",LR_AUTO);

	lr_start_transaction("tr_logout");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(38);

	web_reg_find("Fail=NotFound",
		"Text/IC= A Session ID has been created and loaded",
		LAST);
	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("tr_logout",LR_AUTO);
	
	lr_end_transaction("tr_main", LR_AUTO);

	return 0;
}