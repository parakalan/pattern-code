#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
ofstream f; //CREATED PROGRAM
void suspend(int n)
{
    for(long int x=0; x<10*n; x++)
        for(long int y=0; y<10*n; y++)
            {}
}
void initial_display();
void multi_pattern();
void uni_input();
void uni_check();
void multi_input();
void multi_check();
void multi_assign();
void generatecode();
void assign_status();
void in_count(int , int );
void assign_status();
void in_assign();
void write_to_file();
void display();
void in_display();


char a[100][100]; // Master array of characters.
char temp[100]; // For  " void multi_check() "
int n,s_count[100],ch_count[100],s_in_count[100];
int i,j,d_c,d_s,in_d_s,in_d_c;
char ch,p_type,in_p,ch_p_type='n',ch_type;
int ch_diff;

int main()
{
    char file_name[100];
    char ch_temp[50];
    system("clear");		//clrscr();
    initial_display();
    system("clear");		//clrscr();
    cout<<endl<<"\n Enter File name : ";
    cin>>file_name;
    strcat(file_name,".cpp");
    f.open(file_name);
    f<<"/* SNIPPET TO GENERATE THE FOLLOWING PATTERN:"<<endl;
    while(ch_p_type=='n')
    {
        cout<<endl<<"\n Is the pattern 'uni'-character or 'multi'-character (Enter 'uni' or 'multi') ? ";
        cin>>ch_temp;
        if(!strcasecmp(ch_temp,"multi"))
        {
            ch_p_type='M';
            multi_input();
        }
        else if(!strcasecmp(ch_temp,"uni"))
        {
            ch_p_type='U';
            uni_input();
        }
        else
        {
            cout<<"\n Enter correctly : ";
            suspend(100);
        }
    }
    cout<<endl<<endl<<" PATTERN MATCHES SYNTAX "<<endl;
    generatecode();
    f<<"return 0;"<<endl;
    f<<"}";
    cout<<endl<<"Thank you for using this Code Composing Studio."<<endl;
    cout<<"Please check your output in '"<<file_name<<"'"<<endl<<endl;
    cout<<endl<<endl<<"-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x";
    getchar();
    cout<<endl;
    system("clear");//clrscr();
    cout<<"\t\t\tPATTERN DETAILS :"<<endl;
    for(i=0; i<n; i++)
    {
        puts(a[i]);
    }
    cout<<"\n Number of characters in each line : "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"Line no. "<<i+1<<"-->"<<ch_count[i]<<endl;
    }
    cout<<"\n Number of spaces outside structure: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"Line no. "<<i+1<<"-->"<<s_count[i]<<endl;
    }
    cout<<"\n Number of spaces inside structure: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"Line no. "<<i+1<<"-->"<<s_in_count[i]<<endl;
    }
    cout<<" Pattern Type p_type="<<p_type<<endl;
    cout<<" d_c : "<<d_c<<endl<<" d_s : "<<d_s;
    f.close();
    return 0;
}
void initial_display()
{
    cout<<"\n\n\n";
    cout<<"\t\t\t  CODE COMPOSING STUDIO "<<endl<<endl;
    suspend(500);
    cout<<" -> DO NOT USE UNNECESSARY SPACES "<<endl;
    cout<<"    Example : "<<endl;
    cout<<"    *---"<<endl;
    cout<<"    **--"<<endl;
    cout<<"    ***-"<<endl;
    suspend(500);
    cout<<endl;
    cout<<" -> DO NOT ENTER ABSURD 'PATTERNS'."<<endl;
    suspend(500);
    cout<<endl;
    cout<<" -> ENTER '-' FOR SPACES."<<endl;
    suspend(500);
    cout<<endl;
    cout<<" ->  A FEW UNI-CHARACTER PATTERNS USER MAY ENTER:"<<endl;
    suspend(500);
    cout<<"  1.*	  2.****	 3.---*     4. ****"<<endl;
    cout<<"    **	    ***	           --**        -***"<<endl;
    cout<<"    ***     **	           -***        --**"<<endl;
    cout<<"    ****    *	     	   ****        ---*"<<endl;
    suspend(500);
    cout<<endl;
    cout<<"  5.*****  6.**     7.---**     8. ---*"<<endl;
    cout<<"    *****    -**      --**         --***"<<endl;
    cout<<"    *****    --**     -**          -*****"<<endl;
    cout<<"    *****    ---**    **           *******"<<endl;
    suspend(500);
    cout<<endl;
    cout<<"  9.*"<<endl;
    cout<<"    -**"<<endl;
    cout<<"    --***"<<endl;
    cout<<"    ---****"<<endl;
    getchar();
    system("clear");
    cout<<"\n\n\n";
    cout<<"\t\t\t  CODE COMPOSING STUDIO "<<endl<<endl;
    cout<<" -> ONLY THE FOLLOWING MULTI-CHARACTER PATTERNS ARE COMPATIBLE : "<<endl;
    cout<<endl;
    cout<<"  1.A	  2.ABCD	 3.---A     4. ABCD"<<endl;
    cout<<"    AB	    ABC	           --AB        -ABC"<<endl;
    cout<<"    ABC     AB	           -ABC        --AB"<<endl;
    cout<<"    ABCD    A	     	   ABCD        ---A"<<endl;
    suspend(500);
    cout<<endl<<endl;
    cout<<"  5.ABCDE  6.AB     7.---AB     8. ---A"<<endl;
    cout<<"    ABCDE    -CD      --CD         --ABC"<<endl;
    cout<<"    ABCDE    --EF     -EF          -ABCDE"<<endl;
    cout<<"    ABCDE    ---GH    GH           ABCDEFG"<<endl;
    suspend(500);
    cout<<endl<<endl;
    cout<<"  9.A"<<endl;
    cout<<"    -AB"<<endl;
    cout<<"    --ABC"<<endl;
    cout<<"    ---ABCD"<<endl;
    getchar();

}
void uni_input()
{
    cout<<"\n Enter Character of Pattern  :- ";
    cin>>ch;
    cout<<"\n Enter '-' for spaces. Enter 'n' after you finish entering the pattern. ";
    cout<<"\n Enter Pattern :"<<endl<<" ";
    for(i=0;; i++)
    {
        cin>>a[i];
        if(a[i][0]=='N'||a[i][0]=='n')
        {
            break;
        }
        f<<endl;
        for(j=0; a[i][j]; j++)
        {
            if(a[i][j]=='-')
            {
                f<<" ";
            }
            else
            {
                f<<a[i][j];
            }
        }
        cout<<" ";
    }
    a[i][0]='\0';
    n=i;
    f<<endl<<endl<<"*/"<<endl;
    uni_check();
}
void uni_check()
{
    for(i=0; i<n; i++)
    {
        for(j=0; a[i][j]; j++)
        {
            if(a[i][j]!='-'&&a[i][j]!=ch)
            {
                cout<<"UN-KNOWN CHARACTER :  "<<a[i][j];
                cout<<endl;
                cout<<"\t\t\t---> EXITING <---";
                f.close();
                suspend(2000);
                exit(0);
            }
        }
    }
}
void multi_input()
{
    char p,q,r;
    cout<<endl<<"Enter first three distinct characters of pattern : ";
    cin>>p>>q>>r;
    if(q!=(p+r)/2)
    {
        cout<<"\n    ::: WRONG PATTERN ::: ";
        suspend(1000);
        return;
    }
    cout<<endl<<"Enter '-' for spaces. Enter '*' after you finish entering the pattern. "<<endl;
    cout<<endl<<"Enter pattern : "<<endl;
    for(i=0;; i++)
    {
        cin>>a[i];
        if(a[i][0]=='*')
        {
            break;
        }
        f<<endl;
        for(j=0; a[i][j]; j++)
        {
            if(a[i][j]=='-')
            {
                f<<" ";
            }
            else
            {
                f<<a[i][j];
            }
        }
    }
    a[i][0]='\0';
    n=i;
    f<<endl<<endl<<"*/"<<endl;//
    //temp1_copy();
    multi_check();
}
void multi_check()
{
    int k=0;
    for(i=0; i<n; i++)
    {
        for(j=0; a[i][j]; j++)
        {
            if(a[i][j]!='-')
            {
                temp[k++]=a[i][j];
            }
        }
    }
    //'1'
    for(i=0; temp[i]; i++)
    {
        for(j=0; temp[j]; j++)
            if((j!=i)&&(temp[i]==temp[j]))// This part of the code is to check the pattern.Take this as example :
            {
                //  --A
                for(k=j; temp[k-1]; k++)  //  -AB
                {
                    //  ABC
                    temp[k]=temp[k+1];    //  temp @ '1' will be AABABC
                }						  //  temp @ '2' will be ABC .
                temp[k]='\0';			  //  temp will be used to check the correctness of the pattern.
            }
        temp[k]='\0';
    }
    //'2'
    for(i=1; temp[i+1]; i++)
    {
        if(temp[i]-temp[i-1]!=temp[i+1]-temp[i])
        {
            cout<<"\n\t\t---------PATTERN NOT FOLLOWED---------------";
            cout<<"\n\t\t---------------EXITING---------------";
            suspend(1500);
            exit(0);
        }
    }
    multi_assign();
    ch_diff=temp[1]-temp[0];
}
void multi_assign()
{
    char temp[100][100];                //This temp array is used to store the entered characters without spaces.
    for(i=0; i<n; i++)                  // For example :       A
    {
        //                     -AB
        int k=0; 						//                     --ABC
        for(j=0; a[i][j]; j++)          // will be stored as :
        {
            //                     A
            if(a[i][j]!='-')            // 					   AB
            {
                temp[i][k++]=a[i][j];
            }
        }
    }
    if(temp[0][0]==temp[1][0])
    {
        ch_type='N';
    }
    else
    {
        ch_type='O';
    }
    for(i=0; i<n; i++)
    {
        for(j=0; a[i][j]; j++)
        {
            if(a[i][j]!='-')
            {
                a[i][j]='*';
                ch='*';
            }
        }
    }
}
void generatecode()
{
    // CHARACTER COUNT
    for(i=0; i<n; i++)
    {
        for(int j=0; a[i][j]; j++)
        {
            if(a[i][j]==ch)
            {
                ch_count[i]++;
            }
        }
    }
    //SPACE COUNT
    for(i=0; i<n; i++)
    {
        if(a[i][0]==ch)
        {
            in_count(i,0);
            continue;
        }
        for(int j=0; a[i][j]; j++)
        {

            if(a[i][j]=='-')
            {
                s_count[i]++;
            }
            if(a[i][j+1]==ch)
            {
                in_count(i,j);
                break;
            }
        }
    }
    assign_status();
}
void in_count(int i,int j)
{
    int temp;
    for(temp=j+1; a[i][temp]; temp++)
    {
        if(a[i][temp]=='-')
        {
            s_in_count[i]++;
        }
    }
}
void assign_status()
{
    d_c=ch_count[1]-ch_count[0];
    d_s=s_count[1]-s_count[0];
    for(i=1; i<n; i++)
    {
        if(ch_count[i]-ch_count[i-1]!=d_c)
        {
            p_type='O';
        }
    }
    if(d_c>0)
    {
        p_type='I';
    }
    else if(d_c<0)
    {
        p_type='D';
    }
    else
    {
        p_type='C';
    }
    in_assign();
}
void in_assign()
{
    in_d_s=s_in_count[1]-s_in_count[0];
    in_p='N';
    for(i=0; i<n; i++)
    {
        if(s_in_count[i]!=0)
        {
            break;
        }
    }
    if(in_d_s>0)
    {
        in_p='I';
    }
    else if(in_d_s<0)
    {
        in_p='D';
    }
    write_to_file();
}
void write_to_file()
{
    f<<"#include<iostream>"<<endl;
    f<<"using namespace std;"<<endl;
    f<<"int main()"<<endl;
    f<<"{ "<<endl;
    f<<"\tint i,j,n;"<<endl;
    if(ch_p_type=='M')
    {
        if(ch_type=='O')
        {
            f<<"\tchar ch='"<<temp[0]<<"';"<<endl;
        }
        else if(ch_type=='N')
        {
            f<<"\tchar ch;"<<endl;
        }
    }
    f<<"\tcout<<endl<<\" Enter no. of lines to print pattern : \";"<<endl;
    f<<"\tcin>>n;"<<endl;
    f<<"\tfor(i=0;i<n;i++)"<<endl;
    f<<"\t{"<<endl;
    if(ch_type=='N')
    {
        f<<"\t\tch = '"<<temp[0]<<"';"<<endl;
    }
    f<<"\t\tcout<<endl;"<<endl;
    display();
    f<<"\t}"<<endl;
}
void display()
{
    if(d_s==0)
    {
        if(p_type=='I')
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<";j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<d_c<<"*i+"<<ch_count[0]<<";k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;
            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<d_c<<"*i+"<<ch_count[0]<<";k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
        else if(p_type=='D')
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<";j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<"-"<<abs(d_c)<<"*i;k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;
            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<"-"<<abs(d_c)<<"*i;k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
        else
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<";j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<";k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<";k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
    }
    else if(p_type=='I')
    {
        if(d_s>0)
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<"+"<<d_s<<"*i;j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<"+"<<d_c<<"*i;k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<"+"<<d_c<<"*i;k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
        else
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<"-"<<abs(d_s)<<"*i;j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<"+"<<d_c<<"*i;k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<"+"<<d_c<<"*i;k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
    }
    else if(p_type=='D')
    {
        if(d_s<0)
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<"-"<<abs(d_s)<<"*i;j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<"-"<<abs(d_c)<<"*i;k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<"-"<<abs(d_c)<<"*i;k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
        else
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<"+"<<abs(d_s)<<"*i;j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<";
            f<<"' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<"-"<<abs(d_c)<<"*i;k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<"-"<<abs(d_c)<<"*i;k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }
        }
    }
    else if(p_type=='C')
    {
        if(d_s>0)
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<"+i;j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<";
            f<<"' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<";k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<";k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }

        }
        else
        {
            f<<"\t\tfor(j=1;j<="<<s_count[0]<<"-"<<abs(d_s)<<"*i;j++)"<<endl;
            f<<"\t\t{"<<endl;
            f<<"\t\t\tcout<<' ';"<<endl;
            f<<"\t\t}"<<endl;
            f<<"\t\tfor(int k=1;k<="<<ch_count[0]<<";k++)"<<endl;
            f<<"\t\t{"<<endl;
            if(ch_p_type=='M')
            {
                f<<"\t\t\tcout<<ch;"<<endl;
                f<<"\t\t\tch+="<<ch_diff<<";"<<endl;
            }
            else if(ch_p_type=='U')
            {
                f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
            }
            f<<"\t\t}"<<endl;

            if(in_p!='N')
            {
                in_display();
                f<<"\t\tfor(k=1;k<="<<ch_count[0]<<";k++)"<<endl;
                f<<"\t\t{"<<endl;
                if(ch_p_type=='M')
                {
                    f<<"\t\t\tcout<<ch;"<<endl;
                    f<<"\t\t\tch+=ch_diff;"<<endl;
                }
                else if(ch_p_type=='U')
                {
                    f<<"\t\t\tcout<<'"<<ch<<"';"<<endl;
                }
                f<<"\t\t}"<<endl;
            }

        }
    }
}
void in_display()
{
    if(in_p=='I')
    {
        f<<"\t\tfor(j=0;j<"<<s_in_count[0]<<"+"<<in_d_s<<"*i;j++)"<<endl;
        f<<"\t\t{"<<endl;
        f<<"\t\t\tcout<<\" \";"<<endl;
        f<<"\t\t}"<<endl;
    }
    else
    {
        f<<"\t\tfor(j=0;j<"<<s_in_count[0]<<"-"<<abs(in_d_s)<<"*i;j++)"<<endl;
        f<<"\t\t{"<<endl;
        f<<"\t\t\tcout<<\" \";"<<endl;
        f<<"\t\t}"<<endl;
    }
}
