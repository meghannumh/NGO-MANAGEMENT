#include<iostream>
#include<math.h>
#include<fstream>
#include<set>
#include<string>
using namespace std;
class person
{
	       
	 	long int phone;
		char some;
		int age;
		char gender;
		string name;
		string location;
	 	long int pincode;
		public:
 void set_details()
    {
	         cout<<"Enter age:"<<endl;
    	         cin>>age;
	         cout<<"Enter Gender Female(F)/Male(M):"<<endl;
	         cin>>gender;
	         cout<<"Enter name:"<<endl;
	    	 cin>>name;
	         cout<<"Enter location:"<<endl;
	         cin>>location;
     }
  void get_details()
    {
    	  	 cout<<"Name:"<<"\t"<<name<<endl;
    	    	 cout<<"Gender:"<<"\t"<<gender<<endl;
	    	 cout<<"Age:"<<"\t"<<age<<endl;
	    	 cout<<"Location:"<<location<<endl;
    }
void read_details()
    {
 	  	 cout<<"Enter your phone number"<<endl;
 	   	 cin>>phone;
 	   	 cout<<"child labour=c,old age=o,women harrassment=w,mentally disabled=m;physical disorder=p"<<endl;
	   	 cout<<"Enter c (or) o (or) w (or) m (or) p"<<endl;
	   	 cin>>some;
    }
};
class victim:protected person
{
  	      public:
	void details()
     {
   	 	 cout<<"Reading victim details"<<endl;
     	 	 person::set_details();
                // cout<<"Displaying victim details"<<endl;
           	 //person::get_details();
     }
};
int val1,val2;
struct ngo
{
	string name;   
	int age;          
        long int pin ;      
        string area;
        float distance1;
	float distance2;
        float distance;
}n[20];
int i;
class searchngo
{
    	public:
    	float findminimum(int x1,int x2,int y1,int y2)
	  {  
              
  	        return(pow(pow(x2-x1,2)+pow(y2-y1,2),0.5));
	  }
        void distance_info()
	   { 
                  cout<<"Enter the Longitudinal distance(from It park,Hubli)in km:"<<endl;//it park is reference here we are taking all distances from it park  
		  cin>>val1;
                  cout<<"Enter the Latitudinal distance(from It park,Hubli)in km:"<<endl;
                  cin>>val2; 
          }
	 searchngo()
	{
  		  fstream fet("ngo.txt",ios::out|ios::in);
		  if(!fet){
 		  cout<<"file cant be opened"<<endl;
		  exit(1);}
 		  for( i=0;i<20;i++)
	    {
  		  fet>>n[i].name>>n[i].age>>n[i].area>>n[i].distance1>>n[i].distance2>>n[i].pin;
       	    }
	} 
};
bool operator <(const ngo&t,const ngo&t1)
	{
     	    return (t.distance<t1.distance);
	}
class minimum:protected searchngo
{ 
	public:
        void get_distance()
  {		 
                  searchngo a;
		  a.distance_info();
		  fstream fet("ngo.txt",ios::out|ios::in);
		  if(!fet)
            {
  		  cout<<"file cant be opened"<<endl;
		  exit(1);
            }
       for( i=0;i<20;i++)
      {
 	        fet>>n[i].name>>n[i].age>>n[i].area>>n[i].distance1>>n[i].distance2>>n[i].pin;
      }
       for(i=0;i<20;i++)
        {
	       n[i].distance=a.findminimum(n[i].distance1,val1,n[i].distance2,val2);
	       fet<<n[i].distance<<endl;
        }
          int j; 	
          int choice;
while(1)
{
 	 	cout<<"Types of Victims"<<endl;
 	 	cout<<"1.child labour \n2.women harassment \n3.old age \n4.mental or physical disorder \n5.exit"<<endl;
            	cout<<"Select type of victim"<<endl;
 		cin>>choice;
 		cout<<"***Here is the list of NGO's near you****"<<endl;
 	switch(choice)

   {
        case 1:
        { 
                set<struct ngo>s;                    //created an empty set 
            	cout<<"***********child labour**************"<<endl;	  
	        for(int i=0;i<20;i++)
	  {     
		if(n[i].age==14)
	     {	    s.insert(n[i]);
             }
	  }
                    set<struct ngo>::iterator it;
                    it=s.begin();
		    cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                    cout<<it->distance<<"\t"<<"\t"<<it->name<<endl;
                    ++it;
                    cout<<it->distance<<"\t"<<"\t"<<it->name<<endl;
                    ++it;
                    cout<<it->distance<<"\t"<<"\t"<<it->name<<endl;
           break;
       }
   case 2:
      {             cout<<"**********women harassment**********"<<endl;
            	    set<struct ngo>s1; 
           	   for(int i=0;i<20;i++)
	 {      
		   if(n[i].age==15)
		{   
                        s1.insert(n[i]);
	 }	}	
                    set<struct ngo>::iterator it1;
                    it1=s1.begin();
		    cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                    cout<<it1->distance<<"\t"<<"\t"<<it1->name<<endl;
                    ++it1;
                    cout<<it1->distance<<"\t"<<"\t"<<it1->name<<endl;
                    ++it1;
                    cout<<it1->distance<<"\t"<<"\t"<<it1->name<<endl;
           break;
     }
  case 3:
     {              
  		   cout<<"***********old age************"<<endl;
             	   set<struct ngo>s2; 
             for(int i=0;i<20;i++)
	{     
	           if(n[i].age==60)
	   {     
                   s2.insert(n[i]);
        }   }
                    set<struct ngo>::iterator it2;
                    it2=s2.begin();
		    cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                    cout<<it2->distance<<"\t"<<"\t"<<it2->name<<endl;
                    ++it2;
                    cout<<it2->distance<<"\t"<<"\t"<<it2->name<<endl;
                    ++it2;
                    cout<<it2->distance<<"\t"<<"\t"<<it2->name<<endl;
           break;
       }
  case 4:
        {  
                     cout<<"******Mental or physical disabled*********"<<endl;
                     set<struct ngo>s3; 
                     for(int i=0;i<20;i++)
	 {     
		     if(n[i].age==0)
	      {        s3.insert(n[i]);
              }
         }
                    set<struct ngo>::iterator it3;
                    it3=s3.begin();
		    cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                    cout<<it3->distance<<"\t"<<"\t"<<it3->name<<endl;
                    ++it3;
                    cout<<it3->distance<<"\t"<<"\t"<<it3->name<<endl;
                    ++it3;
                    cout<<it3->distance<<"\t"<<"\t"<<it3->name<<endl;
                    break;
      }
  case 5:
          {
  	  exit(1);
          break;
	  }
                default:cout<<"Please Enter the correct choice"<<endl;
      }
}
  }
};
class food:public searchngo
{  
	public:
	int weight;
    	string location;
    	void set_food()
    {
   		cout<<"Enter the weight of the food(we will accept if weight is greater than 20):"<<endl;
   		cin>>weight;
    }
        int j;
 	void get_food()
   {
                searchngo r;
		if(weight>20){
                fstream fet("ngo.txt",ios::out|ios::in);
		if(!fet){
                          cout<<"file cant be opened"<<endl;
		          exit(1);
			}
  		cout<<"Enter the location from where to collect food:"<<endl;
 	        cin>>location;
		r.distance_info();
 		for( i=0;i<20;i++)
	 {
	        fet>>n[i].name>>n[i].age>>n[i].area>>n[i].distance1>>n[i].distance2>>n[i].pin>>n[i].distance;
	 }
		for(i=0;i<20;i++)
	  {
		n[i].distance=r.findminimum(n[i].distance1,val1,n[i].distance2,val2);
		fet<<n[i].distance<<endl;
	  }
 		set<struct ngo>sw;
                for(i=0;i<20;i++)
       {
                    sw.insert(n[i]);
       }
                 set<struct ngo>::iterator its;
                 its=sw.begin();
                 cout<<endl;
		 cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                 cout<<its->distance<<"\t"<<"\t"<<its->name<<endl;
                 ++its;
                 cout<<its->distance<<"\t"<<"\t"<<its->name<<endl;
                 ++its;
                 cout<<its->distance<<"\t"<<"\t"<<its->name<<endl;
    }
		else
	{
       		 cout<<"Sorry we can't take food"<<endl;
	}
  }
};
class natural_disaster
{       
	public:
	char some;
	int choice;
	string area;
	void get_natural_disaster()
	{
		cout<<"Enter the type of natural disaster"<<endl;
		cout<<"Enter f for floods,t for tsunami,e for earth quake,h for fireaccident"<<endl;
		cin>>some;
		cout<<"Enter the area"<<endl;
		cin>>area;
		cout<<"Inform the necessities of victims"<<endl; 
		cout<<"\n1.Food \n2.Clothes \n3.shelter \n4.exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
			{
 			   case 1:  { cout<<"***FOOD****"<<endl;
				     cout<<"Thank you for informing us"<<endl;
				     break;}
		           case 2:  { cout<<"**Clothes***"<<endl;
				     cout<<"We will inform to ngo"<<endl;
				     break;}
			   case 3:  {  cout<<"***Shelter***"<<endl;
				     break;}
			   case 4:   {exit;
 				     break;}
			}
	}
};
struct togetmoney
{
	   string name2; 
	   float distancea;
	   float distanceb;              
	   string area2;
	   long int pin2;
	   float distancef;
}q[6];
int t;
bool operator <(const togetmoney& z,const togetmoney& z1)
   {
          return (z.distancef<z1.distancef);
   }
class fund
{
	  private:
	  long int account_no;
	  long int card_no;
	  int amount;
	  string loc;
	  long int phone_no;
          long phn;
    	  int c;
	  int otp,otp1; 
	  int ch;
	  int choice;
	  public:
	    int get_money()
     {
		      cout<<"\n1.Online transfer\n 2.UPI\n 3.Cash or Cheque\n 4.exit\n"<<endl;
		      cout<<"enter choice"<<endl;
		      cin>>ch;
	          switch(ch)
	 {
			case 1:
	      {
                      cout<<"Welcome to Online transfer"<<endl;
		      cout<<"Enter the amount you want to sponser"<<endl;
		      cin>>amount;
		      cout<<"Enter the card number"<<endl;
		      cin>>card_no;
		      cout<<"Enter your account number"<<endl;
		      cin>>account_no;
		      cout<<"Enter your phone number"<<endl;
		      cin>>phone_no;
		      otp1=1234;int otp2=1379;
		      cout<<"Enter the otp which you received in mobile"<<endl;
		      cin>>otp;
 		      if(otp==otp1||otp==otp2)
	           {
		      cout<<"Transaction sucessfull"<<endl;
		      cout<<"Thank you"<<endl;
		   }
		      else
	           {
	              cout<<"Otp you have entered is wrong,if you have any queries Contact us "<<endl;
		   }
		      cout<<"For confirmation details from ngo"<<endl;
		      cout<<"contact 9876523443"<<endl;
		      cout<<"If you receive confirmation from Ngo then, confirmation sucessfull"<<endl;
		      cout<<"If you didn't receive any confirmation,Report us"<<endl;	 
		      break;
              }
		       case 2:
	      {         
		       cout<<"UPI details"<<endl;
		       cout<<"1.Google pay \n2.Phone pay \n3.pay pal"<<endl;
		       cout<<"Enter your choice"<<endl;
		       cin>>choice;
		       cout<<"Thank you"<<endl;
                       break;
	       }
			case 3:
	       {
			cout<<"Cheque or cash"<<endl; 
			cout<<"Enter your details:"<<endl;
			cout<<"Enter your location:"<<endl;
			cin>>loc;
			cout<<"Enter contact number:"<<endl;
			cin>>phn;
                        searchngo obj;
			obj.distance_info();
                        fstream fez("ngoa.txt",ios::out|ios::in);
                        if(!fez)
		    {
                         cout<<"file cant be opened"<<endl;
                         exit(1);
                    }
                         for( t=0;t<6;t++)
                      {
                          fez>>q[t].name2>>q[t].distancea>>q[t].distanceb>>q[t].area2>>q[t].pin2;
                      }
                          for(t=0;t<6;t++)
                         {
                           q[t].distancef=obj.findminimum(q[t].distancea,val1,q[t].distanceb,val2);
                           fez<<q[t].distancef<<endl;
                         }
                          for(t=0;t<6;t++)
                         {
                            cout<<"Distance"<<t<<"\t"<<q[t].distancef<<endl;
                         }
                             set<struct togetmoney>tocm;
                             for(t=0;t<6;t++){
                             tocm.insert(q[t]);}
                             set<struct togetmoney>::iterator itc;
                             itc=tocm.begin();
                             cout<<endl;
			     cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                             cout<<itc->distancef<<"\t"<<"\t"<<itc->name2<<endl;
                             ++itc;
                             cout<<itc->distancef<<"\t"<<"\t"<<itc->name2<<endl;
                             ++itc;
                             cout<<itc->distancef<<"\t"<<"\t"<<itc->name2<<endl;
                             cout<<"Ngo will come soon to collect amount"<<endl;
		             cout<<"Check id proof of ngo before giving money"<<endl;				
   			     break;
		}
			case 4:
		{
				exit;
				break;
	        }
         }
     }
};
struct animal
{ 
	string name1;     
        float x;
    	float y;   
   	string area1;
	long int pin1;  
	string type;
   	float distance3;
}a[10];
 bool operator <(const animal&e,const animal&e1)
       {
            return (e.distance3<e1.distance3);
       }
class animals
{
	 int k; 
         string location;
         string aa;
  	 public:
	void get_animaldetails()
	{
		   cout<<"Enter the location of the animal:"<<endl	;
   		   cin>>location;
		   cout<<"Inform us if you find any animal from this list"<<endl;
		   cout<<"Elephant"<<"\t"<<"Cow"<<"\t"<<"Lion"<<"\t"<<"Deer"<<
                   "\t"<<"Giraffe"<<"\t"<<"Donkey"<<"\t"<<"Monkey"<<"\t"<<"Tiger"<<"\t"<<"Zebra"<<"\t"<<"Peacock"<<endl;
		   cout<<"We can provide services only for this type of animals"<<endl;
		   cout<<"Enter the Type of animal:"<<endl;
   	           cin>>aa;
	}
	void get_animaldistance()
	{
		   fstream ani("animal.txt",ios::out|ios::in);
		   if(!ani)
	    {
  		   cout<<"file cant be opened"<<endl;
	           exit(1);
	    }
        else{
	for(k=0;k<10;k++)
	      {
 		   ani>>a[k].name1>>a[k].x>>a[k].y>>a[k].area1>>a[k].pin1>>a[k].type;
	      }
       for(k=0;k<10;k++)
            {
		   if(a[k].type==aa)
	     	{  
		   searchngo d;
		   cout<<endl;
		   d.distance_info();
	for(k=0;k<10;k++)
	     {
		   a[k].distance3=d.findminimum(a[k].x,val1,a[k].y,val2);
		   ani<<a[k].distance3<<endl;
	     }
	for(k=0;k<10;k++)
	     {
 		   cout<<"Distance"<<k<<"\t"<<a[k].distance3<<endl;
	     }
		   set<struct animal>sa; 
                   for(k=0;k<10;k++)
		{
                    sa.insert(a[k]);
		}
                    set<struct animal>::iterator ita;
                    ita=sa.begin();
                    cout<<endl;
		    cout<<"Distance"<<"\t"<<"Ngo name"<<endl;
                    cout<<ita->distance3<<"\t"<<"\t"<<ita->name1<<endl;
                    ++ita;
                    cout<<ita->distance3<<"\t"<<"\t"<<ita->name1<<endl;
                    ++ita;
                    cout<<ita->distance3<<"\t"<<"\t"<<ita->name1<<endl;
		    cout<<"Thank you for informing us about animal"<<endl;
                    cout<<"We will take care of animal"<<endl;
            }
        }
   }}
     
};
void feedback()
{
		int ch;
		cout<<"\n1.5 star rate\n2.4 star rate\n3.3 star rate\n4.2 star rate\n5.1 star rate\n6.0 star rate\n7.exit\n"<<endl;
		cout<<"enter choice"<<endl;
		cin>>ch;
		switch(ch)
	{
		case 1:
			cout<<"*****"<<endl;
		break;
	
		case 2:
			cout<<"****"<<endl;
		break;
		case 3:
			cout<<"***"<<endl;
		break;
		case 4:
			cout<<"**"<<endl;
			break;
		case 5:
			cout<<"*"<<endl;
		break;
		case 6:
			cout<<""<<endl;
		break;
	}
}
	


int main()
{
         int choice,ch;
	 char ch1;
  		cout<<"*******WELCOME TO NGO MANAGEMENT SYSTEM*******"<<endl;
  		cout<<"If you find any one who wants help please inform us"<<endl;
  		cout<<"We will help them by contacting NGO's"<<endl;
  		cout<<"please select one from below menu"<<endl;
 		cout<<"1.victim \n2.Animal \n3.Sponsership \n4.Food \n5.Natural disaster \n6.exit"<<endl;
  		cout<<"Enter your choice"<<endl;
 		cin>>choice;
   	switch(choice)
    		{
    	case 1:   
	   {
      		cout<<"Inform us about victim details"<<endl;
	       	victim v;
  	       	person p;
                cout<<"Enter your details(you means person)"<<endl;
   	     	p.set_details();
   	      	//cout<<"Displaying your(Person) details"<<endl;
   	      	//p.get_details();
   	      	v.details();
   	      	cout<<"About victim"<<endl;
   	      	p.read_details();
              	minimum m;
               	m.get_distance();
              	cout<<"Thank you for informing us about victim"<<endl;
              	cout<<"We will take care of victim"<<endl;
         break;
	    }
        case 2:   
	    {	      
               cout<<"Inform us about animal details"<<endl;
               animals w;
               w.get_animaldetails();
               w.get_animaldistance();
        break;
	     }
        case 3:
             { 
               cout<<"Sponsorship"<<endl;
               fund f;
               f.get_money();
               cout<<"Thank you for helping needy"<<endl;
       	break;
	      }
 	case 4:
              {
	      	cout<<"Food"<<endl;
              	food b;
              	b.set_food();
	      	b.get_food();
              	cout<<"Thank you for providing food"<<endl;
       break;
	      }
       case 5:
             {
	       cout<<"Natural Disaster"<<endl;
               natural_disaster n;
               n.get_natural_disaster();
               cout<<"Thank you for informing us about natural disaster"<<endl;
       break;
	     }
             
 	case 6: 
	     {
         	exit;
        break;
             	}
     }
		cout<<"!!!!!!!!!!!!!!!!!!!!NEED HELP!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	        cout<<"There has some natural disaster occured"<<endl;
 		cout<<"would you like to lend your hand to help that victims Y(yes) or N(no)"<<endl;
		cin>>ch1;
		if(ch1=='Y')
	{
		cout<<"You want to help through"<<endl;
		cout<<"1.Money \n2.Food"<<endl;
		int x;
		cout<<"Enter 1 for money and 2 for food"<<endl;
		cin>>x;
		if(x==1)	
	      {
  		 fund za;
   		 za.get_money(); 
		 cout<<"Thank you for helping through sponsership"<<endl;
	      }
		if(x==2)
	      {
  		food bq;
   		bq.set_food();
   		bq.get_food();
		cout<<"Thank you for helping through food"<<endl;
	      }
		cout<<"Thank you for lending your hand"<<endl;
	}
		else
	{
  		cout<<"Thank you"<<endl;
	}

		cout<<"please give your feedback"<<endl;	
		feedback();
		cout<<"Thank you for giving feedback"<<endl;
}




