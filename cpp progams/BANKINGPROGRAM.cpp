//security program
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <ctime>

using namespace std;
//void transaction(float accountBalance,float transactionCost,float mount,int option,int success);
//int customer_menu(int opt);
int main()
{
//global variables
       //strings 
string options,options2,options3,confirmedPassword,username,password;
string amount="0";
string amount2="0";

      //integers
int optionRange,optionRange2, optionRange3,homePageOption;
int o=0;
int lock;
      //FLOAT

float accountBalance;
float transactionCost;
float  transactionCosts[50];
float  accountBalancesBefore[50];
float  accountBalancesAfter[50];


		//arrays
string 	transactionNamesArray[50];
string  datesArray[50];
string amountsArray[50];
string statusArray[50];
string timesArray[50];	
		
		//charcters
		//boleans
bool withdrawAmountLocked=false;
bool depositAmountLocked=false;
bool passwordValidation,length;
bool printLengthError=false;
bool printMismatch=false;
bool homepageValidation=false;
bool loginValidation=false;
bool customerMenuIsOpen=false;
bool amountIsVerified=false;
bool toMainMenuOrExitValidation=false;
bool exitCustomerMenu=false;
bool withdrawIsAllowed=false;
bool  insufficientFunds=false;
bool exitDueToInsufficientFunds=false;
bool accountBalanceMenuExitValidation=false;
bool acountBalanceMenuExit=false;
//other



//**********
do{	//homepage display loop
do{
 withdrawAmountLocked=false;
 depositAmountLocked=false;
 lock=0;
  	system("cls");
  system("color 9f");
  cout<<"\n\n\n\n\t\t\t\t\t..................................\n"<<endl;
  cout<<"\t\t\t\t\t|      WELCOME TO STANBIC BANK   |\n"<<endl;
  cout<<"\t\t\t\t\t|................................|\n"<<endl;
  cout<<"\t\t\t\t\t|         1.register             |\n"<<endl;
  cout<<"\t\t\t\t\t|         2.login                |\n"<<endl;
  cout<<"\t\t\t\t\t|         3.exit                 |\n"<<endl;
  cout<<"\t\t\t\t\t|................................|\n"<<endl;
  cin>>options;
  regex f("[1-3]");
  optionRange=stoi(regex_match(options,f)?options:"10");
}while(optionRange==10);
do{
switch(stoi(options)){
	case 1:{
		homePageOption=1;
		system("cls");
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|                   REGISTER                   |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|           Enter prefered username.           |\n"<<endl;
  cout<<"\t\t\t\t\t| Username  :";cin>>username;cout<<endl;              
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
         do{
            regex l("[a-z]+");
            regex n("[0-9A-Z]+");
         do{
		 if(printLengthError){
		 		system("cls");
		 cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t+..............................................+\n"<<endl; 
                         cout<<"\t\t\t\t\t| The password must be 8-16characters long.    |\n"<<endl;  
            cout<<"\t\t\t\t\t+..............................................+\n"<<endl;         
 
         		printMismatch=false;
			 };
		if(printMismatch){
				system("cls");
  cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t+..............................................+\n"<<endl; 
                  cout<<"\t\t\t\t\t|      Password mismatch re-type passwords     |\n"<<endl;  
            cout<<"\t\t\t\t\t+..............................................+\n"<<endl;         
    
		};
  
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|     Enter prefered password                  |\n"<<endl;
  cout<<"\t\t\t\t\t|         Password :";cin>>password;cout<<endl;              
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|     Confirm password                         |\n"<<endl;
  cout<<"\t\t\t\t\t|  Re-type password:";cin>>confirmedPassword;cout<<endl;              
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
            length=(password.length()>7
			&&password.length()<16);
            printLengthError=!length;
            }while(!length);//&&!regex_match(password,s)&&!regex_match(password,u));
			confirmedPassword!=password?passwordValidation=false:passwordValidation=true;
			printMismatch=!passwordValidation;
			passwordValidation?homepageValidation=true:homepageValidation=false;
		}while(!passwordValidation);
		break;
	}
	case 2:{
		do{
	system("cls");
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|                   LOGIN                      |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|  Username :";cin>>username;cout<<endl;              
  cout<<"\t\t\t\t\t                                               |\n"<<endl;
  cout<<"\t\t\t\t\t|  Password :";cin>>password;cout<<endl;              
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;

  loginValidation=true;
}while(!loginValidation); 
        homePageOption=2;
		homepageValidation=true;
		break;
	}
	case 3:{
		    homePageOption=3;
			homepageValidation=true;
		break;
	}
}}while(!homepageValidation);
if(!(homePageOption==3)){
do{
	do{
		
	withdrawAmountLocked=false;
 depositAmountLocked=false;
 lock=0;	
		system("cls");
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|                 CUSTOMER MENU                |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|           1.Deposit                          |\n"<<endl;
  cout<<"\t\t\t\t\t|           2.Withdraw                         |\n"<<endl;
  cout<<"\t\t\t\t\t|           3.Check balance                    |\n"<<endl;
  cout<<"\t\t\t\t\t|           4.Transactions statement           |\n"<<endl;
  cout<<"\t\t\t\t\t|           5.Loans:                           |\n"<<endl;              
  cout<<"\t\t\t\t\t+           6.Logout                           |\n"<<endl;
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cin>>options2;
  regex i("[1-6]");
  optionRange2=stoi(regex_match(options2,i)?options2:"10");
}while(optionRange2==10);
switch(stoi(options2)){
case 1:{
	do{
		//....................DEPOSIT STARTS HERE
	system("cls");
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|                 DEPOSIT                      |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|  MIN 100KES-MAX 100,000,000,000(100BILLION)  |\n"<<endl;              
  cout<<"\t\t\t\t\t|  Enter amount to deposit :";cin>>amount;cout<<endl;              
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
    regex z("[0-9]+");
  optionRange=stoi(regex_match(amount,z)?amount:"10");
  if(optionRange!=10){
  	cout<<sizeof(int)<<endl;
  	cout<<(stoi(amount)<100)<<endl;
  	if(stoi(amount)<100||stoi(amount)>100000){
  		 amountIsVerified=false;
	  }else{
	  	amountIsVerified=true;
	  }
  };
}while(!amountIsVerified||optionRange==10);
do{
	if(!depositAmountLocked){
		
		  	time_t now=time(0);
tm*localTime=localtime(&now);
	transactionCost=0.00;
	accountBalance+=stoi(amount);	
 datesArray[o]=(localTime->tm_mday<10?"0"+to_string(localTime->tm_mday):to_string(localTime->tm_mday))+":"+((1+localTime->tm_mon)<10?"0"+to_string(1+localTime->tm_mon):to_string(1+localTime->tm_mon))+":"+to_string(1900+localTime->tm_year);
 timesArray[o]=(localTime->tm_hour<10?"0"+to_string(localTime->tm_hour):to_string(localTime->tm_hour))+":"+(localTime->tm_min<10?"0"+to_string(localTime->tm_min):to_string(localTime->tm_min))+":"+(localTime->tm_sec<10?"0"+to_string(localTime->tm_sec):to_string(localTime->tm_sec));
 	
transactionCosts[o]=transactionCost;
 accountBalancesBefore[o]=accountBalance-stoi(amount);
 accountBalancesAfter[o]=accountBalance;
 transactionNamesArray[o]="deposit";
 amountsArray[o]=amount;
 statusArray[o]="sucess";
  o++;
	
	lock=1;
};

  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|             DEPOSIT SUCCESIFUL               |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  AMOUNT           |";cout<<amount<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  ACCOUNT BALANCE  |";cout<<accountBalance<<endl;      
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;        
  cout<<"\t\t\t\t\t|  TRANSACTION COST |"; cout<<transactionCost<<endl;             
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS:1 TO GO BACK TO CUSTOMER MENU      |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS: 2 TO LOGOUT                       |\n"<<endl;
  cout<<"\t\t\t\t\t|.....Option:";cin>>options2;cout<<endl; 
  regex j("[1-2]");
  optionRange2=stoi(regex_match(options2,j)?options2:"10");
  optionRange2==10?toMainMenuOrExitValidation=false:toMainMenuOrExitValidation=true;
  
if(lock){	
depositAmountLocked=true;	
}
	
}while(!toMainMenuOrExitValidation);
switch(stoi(options2)){
	case 1:{
		customerMenuIsOpen=true;
		break;
	}
	case 2:{
	customerMenuIsOpen=false;
		break;
	}
}

break;}
//.................DEPOSIT ENDS HERE..............


//..............WITHDRAW STARTS HERE.....
case 2:{
	//withdraw
		do{

	system("cls");
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|                 WITHDRAW                      |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|  MIN 100KES-MAX 10,000,000,000(10BILLION)  |\n"<<endl;  
  insufficientFunds?cout<<"\t\t\t\t\t|........you have insufficient funds.........|\n"<<endl:cout<<"\t\t\t\t\t|..............................................|\n"<<endl;;           
  cout<<"\t\t\t\t\t|  Enter amount withdraw :";cin>>amount2;cout<<endl;              
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
      regex x("[0-9]+");
  optionRange=stoi(regex_match(amount2,x)?amount2:"10");
  if(optionRange!=10){
  	cout<<(stoi(amount2)<100)<<endl;
  	if(stoi(amount2)<100||stoi(amount2)>100000){
  		 amountIsVerified=false;
	  }else{
	  	transactionCost=0.01*stoi(amount2);
	  	amountIsVerified=true;
	    if((accountBalance-(transactionCost+stoi(amount2)))<0){
	    withdrawIsAllowed=false;
	    insufficientFunds=true;
	    amountIsVerified=false;
	    
	   do{
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|       PRESS:1 TO CHECK BALANCE               |\n"<<endl;
  cout<<"\t\t\t\t\t|       PRESS:2 TO GO TO MAIN DEPOSITING MENU  |\n"<<endl;
  cout<<"\t\t\t\t\t|       PRESS:3 TO LOGOUT                      |\n"<<endl;
  cout<<"\t\t\t\t\t|.....Option:";cin>>options2;cout<<endl; 
	   	 regex w("[1-3]");
  optionRange2=stoi(regex_match(options2,w)?options2:"10");
  optionRange2==10?exitDueToInsufficientFunds=false:exitDueToInsufficientFunds=true;
	   }while(!exitDueToInsufficientFunds);
switch(stoi(options2)){
	case 1:{
		
do{			
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|          ACCOUNT BALANCE MENU               |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  ACCOUNT BALANCE  |";cout<<accountBalance<<endl;      
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;        
  cout<<"\t\t\t\t\t|  TRANSACTION COST |"; cout<<"0.00"<<endl;             
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS:1 TO GO BACK TO CUSTOMER MENU      |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS: 2 TO LOGOUT                       |\n"<<endl;
  cout<<"\t\t\t\t\t|.....Option:";cin>>options2;cout<<endl;
		 regex w("[1-2]");
  optionRange2=stoi(regex_match(options2,w)?options2:"10");
  optionRange2==10?accountBalanceMenuExitValidation=false:accountBalanceMenuExitValidation=true;
}while(!accountBalanceMenuExitValidation);		
	switch(stoi(options2)){
		
	case 1:{
		toMainMenuOrExitValidation=true;
		customerMenuIsOpen=true;
		withdrawIsAllowed=true;
		amountIsVerified=true;
		break;
	}case 2:{
		withdrawIsAllowed=true;
		amountIsVerified=true;
		toMainMenuOrExitValidation=true;
		customerMenuIsOpen=false;
		break;
	}	
	};	
			
		break;
	}
	case 2:{
		withdrawIsAllowed=true;
		amountIsVerified=true;
		toMainMenuOrExitValidation=true;
		customerMenuIsOpen=true;
		break;
	}case 3:{
		withdrawIsAllowed=true;
		amountIsVerified=true;
		toMainMenuOrExitValidation=true;
		customerMenuIsOpen=false;
	}
}
		}else{
			withdrawIsAllowed=true;
			toMainMenuOrExitValidation=false;
		};	
	  }
  }else{
  	withdrawIsAllowed=false;
  	amountIsVerified=false;
  }
}while(!amountIsVerified||!withdrawIsAllowed);
if(!toMainMenuOrExitValidation){
do{ 
  if(!withdrawAmountLocked){
  	
  	//time now
  	time_t now=time(0);
tm*localTime=localtime(&now);
	transactionCost=0.01*stoi(amount2);
	accountBalance+(stoi(amount2)+transactionCost);
	 transactionCosts[o]=transactionCost;
 accountBalancesBefore[o]=accountBalance+(stoi(amount2)+transactionCost);
 accountBalancesAfter[o]=accountBalance;
 transactionNamesArray[o]="withdraw";
 datesArray[o]=(localTime->tm_mday<10?"0"+to_string(localTime->tm_mday):to_string(localTime->tm_mday))+":"+((1+localTime->tm_mon)<10?"0"+to_string(1+localTime->tm_mon):to_string(1+localTime->tm_mon))+":"+to_string(1900+localTime->tm_year);
 timesArray[o]=(localTime->tm_hour<10?"0"+to_string(localTime->tm_hour):to_string(localTime->tm_hour))+":"+(localTime->tm_min<10?"0"+to_string(localTime->tm_min):to_string(localTime->tm_min))+":"+(localTime->tm_sec<10?"0"+to_string(localTime->tm_sec):to_string(localTime->tm_sec));
 amountsArray[o]=amount2;
 statusArray[o]="sucess";
 
 o++;
 
	
	lock=1;
};


  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|             WITHDRAW SUCCESIFUL              |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  AMOUNT           |";cout<<amount2<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  ACCOUNT BALANCE  |";cout<<accountBalance<<endl;      
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;        
  cout<<"\t\t\t\t\t|  TRANSACTION COST |"; cout<<transactionCost<<endl;             
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS:1 TO GO BACK TO CUSTOMER MENU      |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS: 2 TO LOGOUT                       |\n"<<endl;
  cout<<"\t\t\t\t\t|.....Option:";cin>>options2;cout<<endl; 
  regex j("[1-2]");
  optionRange2=stoi(regex_match(options2,j)?options2:"10");
  optionRange2==10?toMainMenuOrExitValidation=false:toMainMenuOrExitValidation=true;
if(lock){
withdrawAmountLocked=true;	
}
}while(!toMainMenuOrExitValidation);
switch(stoi(options2)){
	case 1:{
	customerMenuIsOpen=true;
		break;
	}
	case 2:{
	customerMenuIsOpen=false;
		break;
	}
}
};
break;}
//.................WITHDRAW  ENDS HERE...............

//.............CHECK .BALANCE STARTS HERE........
case 3:{
	cout<<"check balance"<<endl;
	
	do{
  cout<<"\t\t\t\t\t+..............................................+\n"<<endl;
  cout<<"\t\t\t\t\t|          ACCOUNT BALANCE MENU               |\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  ACCOUNT BALANCE  |";cout<<accountBalance<<endl;      
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;        
  cout<<"\t\t\t\t\t|  TRANSACTION COST |"; cout<<"0.00"<<endl;             
  cout<<"\t\t\t\t\t|..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS:1 TO GO BACK TO CUSTOMER MENU      |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS: 2 TO LOGOUT                       |\n"<<endl;
  cout<<"\t\t\t\t\t|.....Option:";cin>>options2;cout<<endl;
  		 regex w("[1-2]");
  optionRange2=stoi(regex_match(options2,w)?options2:"10");
  optionRange2==10?acountBalanceMenuExit=false:acountBalanceMenuExit=true;
}while(!acountBalanceMenuExit);		
	switch(stoi(options2)){
		
	case 1:{
		customerMenuIsOpen=true;

		break;
	}case 2:{
		customerMenuIsOpen=false;
		break;
	}	
	};
	
	break;
}
//........CHECK BALANCE ENDS HERE......


//...........TRANSACTION SSTATEMENT STARTS HERE
case 4:{
	cout<<"transaction statement"<<endl;
	
		do{
		system("cls");
  cout<<"\t\t\t\t\t+...............................................................................................................................................+\n"<<endl;
  cout<<"\t\t\t\t\t|                                                          TRANSACTIONS STATEMENTS                                                               |\n"<<endl;
  cout<<"\t\t\t\t\t|................................................................................................................................................|\n"<<endl;
  cout<<"\t\t\t\t\t|  Transaction Name  |     Date    |    Time    |  Amount|Transaction cost  |  Account balance before  |  Account balance after  |  statusArray  |\n"<<endl;     
  cout<<"\t\t\t\t\t|....................|.............|............|........|..................|..........................|.........................|...............|\n"<<endl;    
  for(int i=0;i<o;i++){
  	cout<<"\t\t\t\t\t| ";
	  cout<<transactionNamesArray[i];
for(int ij=0;ij<(20-transactionNamesArray[i].length());ij++){
	ij+transactionNamesArray[i].length()==19?cout<<"|":	cout<<" ";
};
	  cout<<datesArray[i];
for(int ik=0;ik<(14-datesArray[i].length());ik++){
	ik+datesArray[i].length()==13?cout<<"|":	cout<<" ";
};	      
	  cout<<timesArray[i];
	 
for(int il=0;il<(13-timesArray[i].length());il++){
	il+timesArray[i].length()==12?cout<<"|":	cout<<" ";
};	 
	 
	  
	  cout<<amountsArray[i];
	  
	  for(int im=0;im<(9-amountsArray[i].length());im++){
	im+amountsArray[i].length()==8?cout<<"|":	cout<<" ";
};
	  
	  	stringstream s;
	
	;
	   string resul;
	  
	  
	  cout<<transactionCosts[i];
	    s<<transactionCosts[i];
      	resul =s.str();
	  
	  for(int in=0;in<(19-resul.length());in++){
	in+resul.length()==18?cout<<"|":	cout<<" ";
};
	  
	  cout<<accountBalancesBefore[i];
	  
	   s<<accountBalancesBefore[i];
      	resul =s.str();
	  
	  for(int io=0;io<(28-resul.length());io++){
	io+resul.length()==27?cout<<"|":	cout<<" ";
};

//debbug here
	  cout<<accountBalancesAfter[i];
	   s<<accountBalancesAfter[i];
      	resul =s.str();
	  for(int ip=0;ip<(29-resul.length());ip++){
	ip+resul.length()==28?cout<<"|":	cout<<" ";
};
	  
	  cout<<statusArray[i];
	  for(int iq=0;iq<(16-statusArray[i].length());iq++){
	iq+statusArray[i].length()==15?cout<<"|":	cout<<" ";
};

	  cout<<endl;
  	cout<<"\t\t\t\t\t|....................|.............|............|........|..................|..........................|.........................|...............|\n"<<endl;
  };   
  cout<<"\t\t\t\t\t|                                              |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS:1 TO GO BACK TO CUSTOMER MENU      |\n"<<endl;
  cout<<"\t\t\t\t\t|     PRESS: 2 TO LOGOUT                       |\n"<<endl;
  cout<<"\t\t\t\t\t+..............................................|\n"<<endl;
  cout<<"\t\t\t\t\t|.....Option:";cin>>options2;cout<<endl;
  		 regex w("[1-2]");
  optionRange2=stoi(regex_match(options2,w)?options2:"10");
  optionRange2==10?acountBalanceMenuExit=false:acountBalanceMenuExit=true;
}while(!acountBalanceMenuExit);		
	switch(stoi(options2)){
		
	case 1:{
		customerMenuIsOpen=true;

		break;
	}case 2:{
		customerMenuIsOpen=false;
		break;
	}	
	};
	
	
	
	break;
}
//...........TRANSACTION SSTATEMENT ENDS HERE
case 5:{
	cout<<"loans"<<endl;
	break;
}
case 6:{
	cout<<"logout"<<endl;
	customerMenuIsOpen=false;
	break;
}
}
  
}while(customerMenuIsOpen);
}
}while(optionRange!=3);
return(0);
}

    
