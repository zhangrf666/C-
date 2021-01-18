#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

enum Sex {male,female};

/***********************************************************************************/
class enroll{//�û���¼��
private:
 string name;
 string password;
public :
bool check();//��¼ʱ���
void  change();//�޸��û���������
void load();
void save();

enroll(){
load();
//cout<<name<<"   "<<password;
}
};


bool enroll::check(){    
string a,b;
cout<<"���� �û���"<<endl;
cin>>a;
cout<<"���� ����"<<endl;
cin>>b;
if (a==name&&b==password)
return true;
else 
return false;
}

void enroll::change(){
string a,b;
cout<<"���� name"<<endl;
cin>>a;
cout<<"���� password"<<endl;
cin>>b;
name=a;
password=b;
save();
cout<<"����Ķ��Ѿ�����"<<endl;
};

void enroll ::load(){
string a,b;
ifstream fin("pass.txt");
fin>>a>>b;
name=a;
password=b;
fin.close();
}
void enroll::save(){
	ofstream fout("pass.txt",ios_base::trunc);
	fout<<name<<"\t"<<password;
	fout.close();
}


/***********************************************************************************/
class person{           //������Ϣ
protected:
	string name;   
	Sex sex;
	int year, month, date;
	string phonenum;
	string email;
	string text; 
public:
	void show();  //չʾ������Ϣ
	void change();  //�޸ĸ�����Ϣ
	void deleteinfo();  //ɾ��������Ϣ
	void load();   //������Ϣ
	void save();   //������Ϣ
	string getname (){ return  name;}
    string getphonenum(){return phonenum;}
	int getSex(){return (int)sex;}
	int getyear(){return year;}
	int getmonth(){return month;}
	int getdate(){return date;}
	string getemail(){return email;}
	string gettext(){return text;}
	person();
	person(string name1,Sex sex1, int year1,int month1, int date1,string phonenumr1,string email1,string text1);
	};
person::person(){ load();}
person::person(string name1,Sex sex1=male, int year1=2019,int month1=1,int date1=1,string phonenum1="",string email1="",string text1=""){
    name=name1;
    sex=sex1;
	year=year1;
	month=month1;
	date=date1;
	phonenum=phonenum1;
	email=email1;
	text=text1;

}
void person::show(){
	string a;
	if (year==-858993460|month==-858993460|date==-858993460){
		cout<<"����Ϣ����Ϣ�������������޸ĸ�����Ϣ�����"<<endl;return;}
	if (sex==male)
		a="male";
	else
	    a="female";

		cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"����"<<setw(10)<<name<<"    �Ա�"<<setw(10)<<a<<endl;
		cout<<"�ֻ���"<<setw(20)<<phonenum<<"    ����"<<setw(20)<<email<<endl;
		cout<<"����"<<setw(10)<<year<<"  ��"<<setw(10)<<month<<"  ��"<<setw(10)<<date<<"  ��"<<endl;
		cout<<"����:"<<text<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	}

void person::change(){

int i,t;
string r;
	while(1)
		{
		
			cout<<"������Ҫ�޸ĵ���Ϣ��";
			cout<<"1.���� 2.�Ա� 3.�ֻ��� 4.���� 5.������� 6.�����·� 7.�������� 8.����¼���벻Ҫ������������������������"<<endl;
			cin>>i;
			switch(i){
			case 1:
							{
								cout<<"����������:\n";

								cin>>name;
							}
							break;
						case 2:
							{
								cout<<"�������Ա�1.male 2.female:���벻Ҫ������������������������\n";

								cin>>t;
                                if (t==1)
									sex=male;
								else if (t==2)
									sex=female;
								else 
									cout<<"�������"<<endl;
							}
							break;
						case 3:
							{
								cout<<"�������ֻ���:\n";

								cin>>phonenum;
							}
							break;
						case 4:
							{
								cout<<"����������:\n";

								cin>>email;
							}
							break;
						case 5:
							{
								cout<<"������������:���벻Ҫ������������������������\n";
								cin>>t;
								/*if (t>2020)
									cout<<"������ݲ���ȷ"<<endl;*/

									year=t;
							}
							break;
						case 6:
							{
								cout<<"����������·�:���벻Ҫ������������������������\n";
								cin>>t;
								if (t>12|t<1)
									cout<<"�����·ݲ���ȷ"<<endl;
								else
									month=t;

							}
							break;
						case 7:
							{
								cout<<"�������������:���벻Ҫ������������������������\n";
								cin>>t;
								if (t>31|t<1)
									cout<<"�������ڲ���ȷ"<<endl;
								else
									date=t;

							}
							break;
						case 8:
														{
								cout<<"�����뱸��:\n";
								cin>>text;
							}
							break;

						default:
							cout<<"����ȷ����"<<endl;
			}
						cout<<"�Ƿ�����޸� 1.�����޸� �����������˳��޸�:���벻Ҫ������������������������";
						cin>>i;
						if(i==1)
						continue;	
						else 
						break;		
	}
	//save();
	cout<<"����ɹ�"<<endl;
}

void person::deleteinfo(){
	ofstream fout("person.txt",ios_base::trunc);
	fout.close();
	cout<<"ɾ���ɹ�"<<endl;
}
void person ::load(){
int a;
ifstream fin("person.txt");
if(fin==0)
cout<<"û�п������ݣ������޸ĸ�������ģʽ�����"<<endl;
fin>>name>>a>>year>>month>>date>>phonenum>>email>>text;
sex=(Sex)a;

fin.close();
}
void person::save(){
	int a;
	ofstream fout("person.txt",ios_base::trunc);
	a=sex;
	fout<<name<<"\t"<<a<<"\t"<<year<<"\t"<<month<<"\t"<<date<<"\t"<<phonenum<<"\t"<<email<<"\t"<<text<<"\t";
	fout.close();
}
/***********************************************************************************/

class myfri : public person{
private :
     myfri* mynext;
public:
//void save();

myfri* getnext(){return mynext;}
void setnext(myfri* ptr){mynext=ptr;}
myfri (string name1,Sex sex1, int year1,int month1, int date1,string phonenumr1,string email1,string text1,myfri*t=0):
person(name1,sex1, year1,month1, date1,phonenumr1,email1,text1)
{mynext=t;}
 
};
/*void myfri::save(){
		int a;
	ofstream fout("person.txt",ios_base::trunc);
	a=sex;
	fout<<name<<"\t"<<a<<"\t"<<year<<"\t"<<month<<"\t"<<date<<"\t"<<phonenum<<"\t"<<email<<"\t"<<text<<"\t";
	fout.close();
}
*/


/***********************************************************************************/
class fri{ 
private :
myfri*myfirst;

public:
fri();
fri(string name1,Sex sex1, int year1,int month1, int date1,string phonenumr1,string email1,string text1);
~fri();
void displayRecord();		//��ʾ��¼
void queryRecord();			//��ѯ
void input();     //���̶����³�Ա��Ϣ
void insert(string name1,Sex sex1, int year1,int month1, int date1,string phonenumr1,string email1,string text1);
		//��Ա��������³�Ա��Ϣ
void saveRecords();			//�����¼
void loadRecords();			//��ȡ��¼
void clear();				//��յ�ǰͨѶ¼

};
fri::fri(){
	myfirst=0;
}
fri::fri(std::string name1, Sex sex1, int year1, int month1, int date1, std::string phonenumr1, std::string email1, std::string text1){
	myfirst= new myfri(name1,sex1, year1,month1, date1,phonenumr1,email1,text1);
}

fri::~fri(){
		myfri *next=myfirst,*temp;
		while(next!=NULL)
		{
			temp=next;
			next=next->getnext();
			delete temp;
		}
		myfirst=NULL;


}


void fri::displayRecord(){
	myfri *head=myfirst;
    int i=0;
		while(head!=NULL)
		{
			i++;
            head->show();
			head=head->getnext();
		}
		cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Ŀǰ�ܹ���"<<i<<"����ϵ������"<<endl;
	}

void fri::queryRecord(){
	int i=2;
	string s;
	myfri *head=myfirst, *t;
	cout<<"��ѡ���ѯ��ʽ 1 ��������ѯ  2 ���绰�����ѯ �����˳����벻Ҫ������������������������"<<endl;
	cin>>i;
	switch(i){
		case 1:
			cout<<"����������"<<endl;
			cin>>s;
			while (true){
				if (head->getname()==s){
					cout<<"�ҵ�"<<endl;
					head->show();
					cout<<"�Ƿ�Ҫ�޸�  1�޸�  �������޸ģ��벻Ҫ������������������������"<<endl;
					cin>>i;
						if (i==1)
							head->change();
					break;
				}
				head=head->getnext();
				if (head==0){
                   cout<<"û���ҵ�"<<endl;
				   break;
				}
			}
	       break;
		case 2:
			cout<<"������绰"<<endl;
			cin>>s;
			while (true){
				if (head->getphonenum()==s){
					cout<<"�ҵ�"<<endl;
					head->show();
					cout<<"�Ƿ�Ҫ�޸�  1�޸�  �������޸ģ��벻Ҫ������������������������"<<endl;
					cin>>i;
						if (i==1)
							head->change();
					break;
				}
				head=head->getnext();
				if (head==0){
                   cout<<"û���ҵ�"<<endl;
				   break;
				}
			}
	       break;
		default:
			;
}
}

void fri::insert(string name1,Sex sex1, int year1,int month1, int date1,string phonenumr1,string email1,string text1){
myfri *pers=myfirst;
		if(pers==NULL)
			myfirst=new myfri(name1,sex1, year1,month1, date1,phonenumr1,email1,text1);
		else
		{
			while(pers->getnext()!=NULL)
				pers=pers->getnext();
			pers->setnext(new myfri(name1,sex1, year1,month1, date1,phonenumr1,email1,text1));

		}
	}


void fri::input(){
string name1;Sex sex1; int year1;int month1; int date1;string phonenum1;string email1;string text1;
int t;
cout<<"����������:\n";
cin>>name1;

cout<<"�������Ա�1.male ����.female:���벻Ҫ������������������������\n";
cin>>t;
if (t==1)
sex1=male;
else 
	sex1=female;

cout<<"�������ֻ���:\n";
cin>>phonenum1;

cout<<"����������:\n";
cin>>email1;

cout<<"���������������:���벻Ҫ������������������������\n";
cin>>year1;

cout<<"����������·�:���벻Ҫ������������������������\n";
cin>>month1;
while (month1>12|month1<1){
cout<<"�����·ݲ���ȷ"<<endl;
cout<<"����������·�:���벻Ҫ������������������������\n";
cin>>month1;
}

cout<<"�������������:\n";
cin>>date1;
while (date1>31|date1<1){
cout<<"�������ڲ���ȷ"<<endl;
cout<<"�������������:���벻Ҫ������������������������\n";
cin>>date1;
}

cout<<"�����뱸��:\n";
cin>>text1;

insert(name1,sex1,year1, month1,date1, phonenum1, email1, text1);
cout<<"�½����\n";
}







void fri::saveRecords(){
		ofstream fout("addressbook.txt",ios_base::trunc);
		myfri *pe=myfirst;
		while(pe)
		{

			fout<<pe->getname()<<"\t"<<pe->getSex()<<"\t"<<pe->getyear()<<"\t"<<pe->getmonth()<<"\t"<<pe->getdate()<<"\t"<<pe->getphonenum()<<"\t"<<pe->getemail()<<"\t"<<pe->gettext()<<"\n";
			pe=pe->getnext();
		}
		fout<<endl;
		fout.close();
		cout<<"���ݱ������!\n";	
	}


void fri::loadRecords(){
        string name1;int a; int year1;int month1; int date1;string phonenum1;string email1;string text1;
		ifstream fin("addressbook.txt");
		int i=0;
		while(fin>>name1>>a>>year1>>month1>>date1>>phonenum1>>email1>>text1)
		{
			//fin>>name1>>a>>year1>>month1>>date1>>phonenum1>>email1>>text1;
			insert(name1,(Sex)a,year1, month1,date1, phonenum1, email1, text1);
			i++;
		}
		if(i==0)
		{
			cout<<"����ʧ��,Ŀǰ�ĵ���û������!"<<endl;
			fin.close();
		}
		else
		{
			fin.close();
			cout<<"�ѳɹ�����"<<i<<"������"<<endl;
			//displayRecord();
		}


}


void fri::clear(){
		myfri* head=myfirst;
		myfri* fhead=head;
		ofstream fout("addressbook.txt",ios::trunc);
		while(head!=NULL)
		{
			fhead=head->getnext();
			delete head;
			head=fhead;
			
		}
		myfirst=NULL;
		fout.close();
		cout<<"����������!\n";
}

void login(){
 enroll a;
 int i;
    cout<<"--------------------------------------��ӭ�������ͨѶ¼����ϵͳ----------------------------------------------------"<<endl;
    cout<<"���¼"<<endl;
	while(!a.check()){
		cout<<"����������"<<endl;}
	cout<<"������ȷ"<<endl;
    cout<<"�Ƿ��޸ģ�����1�޸ģ��������޸ģ��벻Ҫ������������������������"<<endl;
	cin>>i;
	if (i==1)
		a.change();
	cout<<"��������������,������ϵ�˽��棨�벻Ҫ������������������������"<<endl;
    cin>>i;
	system("cls");
}
void self(){
person b;
int i;
cout<<"--------------------------------------��ӭ"<<b.getname()<<"����--------------------------------------------------------"<<endl;
b.show();
cout<<"�Ƿ��޸ģ�����1�޸ģ�2���������Ϣ ���������޸ģ��벻Ҫ������������������������"<<endl;
cin>>i;
if (i==1){
	b.change();
	b.show();
	b.save();
}
if (i==2){
	b.deleteinfo();
}
cout<<"��������������,������ϵ�˽��棨�벻Ҫ������������������������"<<endl;
cin>>i;
system("cls");
}

void other(){
int i;	
fri c;
 c.loadRecords();
while (1){
cout<<endl;
cout<<"��ѡ��Ҫʹ�õĹ��� 1 ��ʾ������ϵ��  2���Ҳ��޸���ϵ����Ϣ   3�½�ͨѶ¼   4���������ϵ����Ϣ  5 ���沢�˳�  ���벻Ҫ������������������������"<<endl;
cin>>i;
switch(i){
	case 1:
        c.displayRecord();
		break;
	case 2:
        c.queryRecord();
		break;
	case 3:
		c.input();
		break;
	case 4:
		c.clear();
		break;
	case 5:
		c.saveRecords();
		return ;
	default:
		;
}
}
}
int main(){
     login();
     self();
	 other();
	return 0;
}
