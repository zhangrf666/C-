#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

enum Sex {male,female};

/***********************************************************************************/
class enroll{//用户登录类
private:
 string name;
 string password;
public :
bool check();//登录时检查
void  change();//修改用户名和密码
void load();
void save();

enroll(){
load();
//cout<<name<<"   "<<password;
}
};


bool enroll::check(){    
string a,b;
cout<<"输入 用户名"<<endl;
cin>>a;
cout<<"输入 密码"<<endl;
cin>>b;
if (a==name&&b==password)
return true;
else 
return false;
}

void enroll::change(){
string a,b;
cout<<"输入 name"<<endl;
cin>>a;
cout<<"输入 password"<<endl;
cin>>b;
name=a;
password=b;
save();
cout<<"密码改动已经保存"<<endl;
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
class person{           //个人信息
protected:
	string name;   
	Sex sex;
	int year, month, date;
	string phonenum;
	string email;
	string text; 
public:
	void show();  //展示个人信息
	void change();  //修改个人信息
	void deleteinfo();  //删除个人信息
	void load();   //加载信息
	void save();   //保存信息
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
		cout<<"无信息或信息不完整！请在修改个人信息中添加"<<endl;return;}
	if (sex==male)
		a="male";
	else
	    a="female";

		cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"姓名"<<setw(10)<<name<<"    性别"<<setw(10)<<a<<endl;
		cout<<"手机号"<<setw(20)<<phonenum<<"    邮箱"<<setw(20)<<email<<endl;
		cout<<"生日"<<setw(10)<<year<<"  年"<<setw(10)<<month<<"  月"<<setw(10)<<date<<"  日"<<endl;
		cout<<"备忘:"<<text<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	}

void person::change(){

int i,t;
string r;
	while(1)
		{
		
			cout<<"请输入要修改的信息项";
			cout<<"1.姓名 2.性别 3.手机号 4.邮箱 5.出生年份 6.出生月份 7.出生日期 8.备忘录（请不要输入除整数以外的其他数！）"<<endl;
			cin>>i;
			switch(i){
			case 1:
							{
								cout<<"请输入姓名:\n";

								cin>>name;
							}
							break;
						case 2:
							{
								cout<<"请输入性别1.male 2.female:（请不要输入除整数以外的其他数！）\n";

								cin>>t;
                                if (t==1)
									sex=male;
								else if (t==2)
									sex=female;
								else 
									cout<<"输入错误"<<endl;
							}
							break;
						case 3:
							{
								cout<<"请输入手机号:\n";

								cin>>phonenum;
							}
							break;
						case 4:
							{
								cout<<"请输入邮箱:\n";

								cin>>email;
							}
							break;
						case 5:
							{
								cout<<"请输入出生年份:（请不要输入除整数以外的其他数！）\n";
								cin>>t;
								/*if (t>2020)
									cout<<"出生年份不正确"<<endl;*/

									year=t;
							}
							break;
						case 6:
							{
								cout<<"请输入出生月份:（请不要输入除整数以外的其他数！）\n";
								cin>>t;
								if (t>12|t<1)
									cout<<"出生月份不正确"<<endl;
								else
									month=t;

							}
							break;
						case 7:
							{
								cout<<"请输入出生日期:（请不要输入除整数以外的其他数！）\n";
								cin>>t;
								if (t>31|t<1)
									cout<<"出生日期不正确"<<endl;
								else
									date=t;

							}
							break;
						case 8:
														{
								cout<<"请输入备忘:\n";
								cin>>text;
							}
							break;

						default:
							cout<<"请正确输入"<<endl;
			}
						cout<<"是否继续修改 1.继续修改 输入其他数退出修改:（请不要输入除整数以外的其他数！）";
						cin>>i;
						if(i==1)
						continue;	
						else 
						break;		
	}
	//save();
	cout<<"保存成功"<<endl;
}

void person::deleteinfo(){
	ofstream fout("person.txt",ios_base::trunc);
	fout.close();
	cout<<"删除成功"<<endl;
}
void person ::load(){
int a;
ifstream fin("person.txt");
if(fin==0)
cout<<"没有可用数据，请在修改个人数据模式中添加"<<endl;
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
void displayRecord();		//显示记录
void queryRecord();			//查询
void input();     //键盘读入新成员信息
void insert(string name1,Sex sex1, int year1,int month1, int date1,string phonenumr1,string email1,string text1);
		//成员链表插入新成员信息
void saveRecords();			//保存记录
void loadRecords();			//读取记录
void clear();				//清空当前通讯录

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
		cout<<"目前总共有"<<i<<"个联系人数据"<<endl;
	}

void fri::queryRecord(){
	int i=2;
	string s;
	myfri *head=myfirst, *t;
	cout<<"请选择查询方式 1 按姓名查询  2 按电话号码查询 其他退出（请不要输入除整数以外的其他数！）"<<endl;
	cin>>i;
	switch(i){
		case 1:
			cout<<"请输入姓名"<<endl;
			cin>>s;
			while (true){
				if (head->getname()==s){
					cout<<"找到"<<endl;
					head->show();
					cout<<"是否要修改  1修改  其他不修改（请不要输入除整数以外的其他数！）"<<endl;
					cin>>i;
						if (i==1)
							head->change();
					break;
				}
				head=head->getnext();
				if (head==0){
                   cout<<"没有找到"<<endl;
				   break;
				}
			}
	       break;
		case 2:
			cout<<"请输入电话"<<endl;
			cin>>s;
			while (true){
				if (head->getphonenum()==s){
					cout<<"找到"<<endl;
					head->show();
					cout<<"是否要修改  1修改  其他不修改（请不要输入除整数以外的其他数！）"<<endl;
					cin>>i;
						if (i==1)
							head->change();
					break;
				}
				head=head->getnext();
				if (head==0){
                   cout<<"没有找到"<<endl;
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
cout<<"请输入姓名:\n";
cin>>name1;

cout<<"请输入性别1.male 其他.female:（请不要输入除整数以外的其他数！）\n";
cin>>t;
if (t==1)
sex1=male;
else 
	sex1=female;

cout<<"请输入手机号:\n";
cin>>phonenum1;

cout<<"请输入邮箱:\n";
cin>>email1;

cout<<"请输入出生日期年:（请不要输入除整数以外的其他数！）\n";
cin>>year1;

cout<<"请输入出生月份:（请不要输入除整数以外的其他数！）\n";
cin>>month1;
while (month1>12|month1<1){
cout<<"出生月份不正确"<<endl;
cout<<"请输入出生月份:（请不要输入除整数以外的其他数！）\n";
cin>>month1;
}

cout<<"请输入出生日期:\n";
cin>>date1;
while (date1>31|date1<1){
cout<<"出生日期不正确"<<endl;
cout<<"请输入出生日期:（请不要输入除整数以外的其他数！）\n";
cin>>date1;
}

cout<<"请输入备忘:\n";
cin>>text1;

insert(name1,sex1,year1, month1,date1, phonenum1, email1, text1);
cout<<"新建完成\n";
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
		cout<<"数据保存完毕!\n";	
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
			cout<<"加载失败,目前文档内没有数据!"<<endl;
			fin.close();
		}
		else
		{
			fin.close();
			cout<<"已成功加载"<<i<<"行数据"<<endl;
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
		cout<<"数据清除完毕!\n";
}

void login(){
 enroll a;
 int i;
    cout<<"--------------------------------------欢迎进入个人通讯录管理系统----------------------------------------------------"<<endl;
    cout<<"请登录"<<endl;
	while(!a.check()){
		cout<<"错误请重试"<<endl;}
	cout<<"密码正确"<<endl;
    cout<<"是否修改？输入1修改，其他不修改（请不要输入除整数以外的其他数！）"<<endl;
	cin>>i;
	if (i==1)
		a.change();
	cout<<"输入任意数清屏,进入联系人界面（请不要输入除整数以外的其他数！）"<<endl;
    cin>>i;
	system("cls");
}
void self(){
person b;
int i;
cout<<"--------------------------------------欢迎"<<b.getname()<<"进入--------------------------------------------------------"<<endl;
b.show();
cout<<"是否修改？输入1修改，2清除个人信息 ，其他不修改（请不要输入除整数以外的其他数！）"<<endl;
cin>>i;
if (i==1){
	b.change();
	b.show();
	b.save();
}
if (i==2){
	b.deleteinfo();
}
cout<<"输入任意数清屏,进入联系人界面（请不要输入除整数以外的其他数！）"<<endl;
cin>>i;
system("cls");
}

void other(){
int i;	
fri c;
 c.loadRecords();
while (1){
cout<<endl;
cout<<"请选择要使用的功能 1 显示所有联系人  2查找并修改联系人信息   3新建通讯录   4清除所有联系人信息  5 保存并退出  （请不要输入除整数以外的其他数！）"<<endl;
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
