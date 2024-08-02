#include<iostream>
using namespace std;

class MyString
{
	
private:
	char* str;
	int lenght;


	static int stringlenght( char* str )
	{
		int count =0;
		for(int i=0;i<str[i]!='\0';i++){                          //calculates the length of string
			count++;
		}
		return count;
	}


	static char* getstringfrombuffer(char* str)
	{
		char* B = 0;
		int B_Length = stringlenght(str);
		if (B_Length > 0){	
			B = new char[B_Length+1];
			char* tempD = B;
			for (char* temp = str; *temp != '\0'; temp++, tempD++)
				*tempD = *temp;                                                 //deep copy
			*tempD = '\0';
		}
		return B;
	}


	static char* concatenate(char* str1, char* str2)
	{
		char* A=0;
		int I;
		int lenght1= stringlenght(str1);
		int lenght2= stringlenght(str2);
		A=new char[lenght1+lenght2+1];
		
		for(I=0; I<lenght1; I++)
		{
			A[I]=str1[I];
		}
		for(int J=0; J<lenght2; J++)
		{
			A[I]=str2[J];
			I++;
		}
		A[I]='\0';
		return A;
	}

	//including the null char here
	//Add GetStringFromBuffer as private member (helper)
	//Add Concatenate as private member (helper)
	//You can add your class members here
public:

	//-------------DO_NOT_CHANGE REGION starts below---------------------
	//Do not change the prototypes given below
	MyString operator+(const MyString);
	MyString& operator=(const MyString&);
	bool operator<(MyString);	//Comparison on the basis of ascii values
	//-------------End of DO_NOT_CHANGE REGION---------------------

	MyString();
	~MyString();
	bool operator!();
	friend ostream& operator<<(ostream& out, const MyString& );
	friend istream& operator>>(istream& in, MyString& );
	MyString (const MyString& );
	char& operator[](int );
	char* operator()(int a, int len);
	//Add your class members here	
};

MyString::MyString()
{
	lenght=1;
	str= new char[lenght];
	str[0]='\0';
}


MyString::~MyString()
{
	if(str)
	{
		delete[] str;
		str=0;
	}
}


bool MyString::operator!()
{
	int count=0;
	for(int i=0; i<lenght; i++)
	{
		if(str[i]=='\0')
			count++;                   //counter to check if the character array is empty
	}
	if(count==lenght)
		return true;
	else
		return false;
}


MyString MyString::operator+(const MyString rhs)
{
	MyString result;
	char* A;
	int I;
	result.lenght=lenght+rhs.lenght;
	A=concatenate(str, rhs.str);                  //calling concatenate function
	if(result.str)
	{
		delete[] result.str;
		result.str = 0;
	}
	result.str=getstringfrombuffer(A);
	delete[] A;
	A=0;
	return result;
}


MyString& MyString::operator=(const MyString& RHS)
{
		if(&RHS != this)
		{
			lenght=RHS.lenght;
			if(str)
			{
				delete[] str;
				str = 0;
			}
			str = new char[lenght];
			for(int i = 0; i < lenght; i++)
			{
				str[i] = RHS.str[i];
			}
			
		}
		return *this;

}


bool MyString::operator<(MyString rhs)
{
	if (lenght>rhs.lenght)
	{
		return false;
	}
	if (lenght<rhs.lenght)
	{
		return true;
	}
	if(lenght==rhs.lenght)
	{
		for(int i=0; i<lenght; i++)
		{
			if(str[i]<rhs.str[i])
				return true;
			if(str[i]>rhs.str[i])
				return false;
		}
		return false;
	}

}


char& MyString::operator[](int a)
{
	if(a<lenght && a>=0)
	{
		return str[a];
	}
	else
		throw exception("index out of range");


}


MyString::MyString(const MyString& RHS)
	{	
		lenght=RHS.lenght;
		str = new char[lenght+1];
		int i;
		for( i = 0; i < lenght; i++)
		{
			str[i] = RHS.str[i];
		}
		str[i]='\0';
	}


char* MyString::operator()(int a, int len)
{
	if(len==lenght-a)
	{
		char* newstring;
		newstring= new char[len+1];
		int i;
		for(i=0; i<len; i++)
		{
			newstring[i]=str[a];
			a++;
		}
		newstring[i]='\0';

		return newstring;
	}
	else
		throw exception("index out of range");
}
	

ostream& operator<<(ostream& out, const MyString& obj)
{
	for(int i=0; i<obj.lenght; i++)
	{
		out<<obj.str[i];
	}
	return out;	
}


istream& operator>>(istream& in, MyString& obj)
{
	char temp[50];
	in >> temp;
	if(obj.str)
	{
		delete[] obj.str;
		obj.str=0;
	}
	obj.str=obj.getstringfrombuffer(temp);
	obj.lenght=obj.stringlenght(obj.str);
	return in;	// to enable cascading
}

//--------------------------Add your code here----------------------

//-------------DO_NOT_CHANGE REGION starts below---------------------
void main()
{
	MyString str1, str2, str3, str4;	//Default constructor will make a string of lenght 1 having null character only i.e. empty string
	
	if(!str1)
	{
		cout<<"String 1 is Empty.\n";
		cout<<"Str 1 = "<<str1<<endl<<endl<<endl;
	}
	
	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;
		

	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl<<endl<<endl;

	//What is following code testing?
	cout<<"Before str1 = str1; str1 = "<<str1<<endl;
	str1 = str1;
	cout<<"After str1 = str1, str1 = "<<str1<<endl<<endl<<endl;


	cout<<"Before str4 = str3 = str1+str2\n";
	cout<<"str1 = "<<str1<<endl;
	cout<<"str2 = "<<str2<<endl;
	cout<<"str3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;

	str4 = str3 = str1+str2;


	cout<<"\n\n\nAfter str4 = str3 = str1+str2\n";
	cout<<"str1 = "<<str1<<endl;
	cout<<"str2 = "<<str2<<endl;
	cout<<"str3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;

	cout<<"\n\n\nEnter String 3:\t";
	cin >> str3;

	cout<<"\n\n\nEnter String 4:\t";
	cin >> str4;

	
	cout<<"\n\n\nstr3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;

	if(str3 < str4)
		cout<<"String 3 is Less than String 4.\n";
	else
		cout<<"String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 .
	//Function Call str5.operator()(5,10) Let the returned MyString or char* leak


	system("pause");
}