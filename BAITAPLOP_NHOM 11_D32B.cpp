// CHUONG TRINH QUAN LY CAC LOP

// NHOM 11 - LOP D32B

// 1.PHAM MINH TUAN
// 2.TRAN TUAN CUONG
// 3.CA VAN TUYEN
// 4.HOANG MINH QUANG
// 5.TRAN THANH TUNG

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include <fstream>
#include <string>

using namespace std;

#define n 40

FILE *f;

int i,j,k,p,so;
void menu(void);

typedef struct {       //KHAI BAO CAU TRUC LOP
    char tenLop[6];
    int sohv,sohvg,sohvk,sohvtbk,sohvtb,sohvy,canhcao,khientrach;
    char thidua[10];
} LOP;

LOP ds[n];

void luuf(int i)
{
    f=fopen("DL.DAT","a+b");
    fwrite(&ds[i],sizeof(LOP),1,f);
    fclose(f);
}

void docf(void)
{
    f=fopen("DL.DAT","rb");
    if (f == NULL) {f=fopen("DL.DAT","a+b");fclose(f);}
    f=fopen("DL.DAT","rb");
    j = 1;
    while(!feof(f))
    {
        fread(&ds[j],sizeof(LOP),1,f);
        j++;
    }
    so=j-1;
}

void nhap(int i)
{
    char tl = 'y';
    while(tl == 'y' || tl == 'Y')
    {
        cout<<"Nhap TEN LOP: ";cin>>ds[i].tenLop;
        cout<<"Nhap SO HOC VIEN: ";cin>>ds[i].sohv;
        cout<<"Nhap SO HOC VIEN GIOI: ";cin>>ds[i].sohvg;
        cout<<"Nhap SO HOC VIEN KHA: ";cin>>ds[i].sohvk;
        cout<<"Nhap SO HOC VIEN TRUNG BINH KHA: ";cin>>ds[i].sohvtbk;
        cout<<"Nhap SO HOC VIEN TRUNG BINH: ";cin>>ds[i].sohvtb;
        cout<<"Nhap SO HOC VIEN BI KI LUAT CANH CAO: ";cin>>ds[i].canhcao;
        cout<<"Nhap SO HOC VIEN BI KI LUAT KHIEN TRACH: ";cin>>ds[i].khientrach;
        ds[i].sohvy = ds[i].sohv - ds[i].sohvg - ds[i].sohvk - ds[i].sohvtbk - ds[i].sohvtb;
        if(ds[i].sohvg >= 2 && ds[i].sohvk >= 18 && ds[i].canhcao == 0 && ds[i].khientrach == 0 && ds[i].sohvy == 0) strcpy(ds[i].thidua,"XUAT SAC");
        else if(ds[i].sohvg >= 1 && ds[i].sohvk >= 11 && ds[i].canhcao == 0 && ds[i].sohvy == 0) strcpy(ds[i].thidua,"TIEN TIEN");
             else strcpy(ds[i].thidua,"KHONG");
        cout<<"BAN CO MUON NHAP TIEP KHONG: <y/n> ";cin>>tl;
        luuf(i);
        i++;
    }
}

void tieude(void)
{
    cout<<"\n|****************************************  NAM HOC 2016 - 2017 *********************************************|";
    cout<<"\n+-----+-------+-----------+---------+--------+----------+-------+--------+---------+------------+-----------+";
    cout<<"\n| STT |  LOP  | SOHOCVIEN | HV GIOI | HV KHA | HV TBKHA | HV TB | HV YEU | CANHCAO | KHIENTRACH | THUDUALOP |";
    cout<<"\n+-----+-------+-----------+---------+--------+----------+-------+--------+---------+------------+-----------+";
    cout<<"\n";
}

void inra(int i)
{
    cout<<'|'<<setw(4)<<i<<".|"<<setw(7)<<ds[i].tenLop<<'|'<<setw(11)<<ds[i].sohv<<'|'<<setw(9)<<ds[i].sohvg<<'|';
    cout<<setw(8)<<ds[i].sohvk<<'|'<<setw(10)<<ds[i].sohvtbk<<'|'<<setw(7)<<ds[i].sohvtb<<'|'<<setw(8)<<ds[i].sohvy<<'|';
    cout<<setw(9)<<ds[i].canhcao<<'|'<<setw(12)<<ds[i].khientrach<<'|'<<setw(11)<<ds[i].thidua<<'|'<<endl;
}

void sapxep(int i)
{
    LOP tam;
    docf();
    if(i == 1)
    {
        for(k=so-1;k>0;k--)
            for(j=1;j<so-1;j++)
                if(strcmp(ds[j].tenLop,ds[j+1].tenLop) > 0)
                {
                    tam=ds[j];
                    ds[j]=ds[j+1];
                    ds[j+1]=tam;
                }

    }
    if(i == 2)
    {
        for(k=so-1;k>0;k--)
            for(j=1;j<so;j++)
                if(ds[j].sohvk < ds[j+1].sohvk)
                {
                    tam=ds[j];
                    ds[j]=ds[j+1];
                    ds[j+1]=tam;
                }
    }
    if(i==3)
    {
        for(k=so-1;k>0;k--)
            for(j=1;j<so;j++)
                if(ds[j].sohvg < ds[j+1].sohvg)
                {
                    tam=ds[j];
                    ds[j]=ds[j+1];
                    ds[j+1]=tam;
                }
    }

}

void case1(void)
{
    system("cls");
    docf();
    for(i=1;i<so;i++) cout<<setw(3)<<i<<"."<<setw(8)<<ds[i].tenLop<<endl;
    getch();getch();
    system("cls");
    menu();
}

void case2(void)
{
    system("cls");
    docf();
    char tam[6];
    cout<<"Nhap TEN LOP: ";cin>>tam;
    for(i=1;i<=so;i++) if(strcmpi(ds[i].tenLop,tam) == 0) {tieude();inra(i);break;}
    getch();getch();
    menu();
}

void case3(void)
{
    system("cls");
    docf();
    tieude();
    for(i=1;i<so;i++) inra(i);
    getch();
    system("cls");
    menu();
}

void case4(void)
{
    system("cls");
    docf();
    nhap(so);
    getch();
    system("cls");
    menu();
}

void case5(void)
{
    char tam1[6],tam2[15],tl;
    system("cls");
    docf();
    cout<<"Nhap TEN LOP can sua thong tin: ";cin>>tam1;
    for(i=1;i<so;i++) if(strcmpi(ds[i].tenLop,tam1) == 0) break;
    tieude();
    inra(i);
    re:cout<<"Ban muon sua thong tin gi ? <sohocvien/hvgioi/hvkha/hvtbk/hvtb/hvyeu/canhcao/khientrach/thidua> <Viet lien khong dau> \n";cin>>tam2;
    cout<<"Nhap gia tri moi: ";
    if(strcmpi(tam2,"sohocvien") == 0) cin>>ds[i].sohv;
    if(strcmpi(tam2,"hvgioi") == 0) cin>>ds[i].sohvg;
    if(strcmpi(tam2,"hvkha") == 0) cin>>ds[i].sohvk;
    if(strcmpi(tam2,"hvtbk") == 0) cin>>ds[i].sohvtbk;
    if(strcmpi(tam2,"hvtb") == 0) cin>>ds[i].sohvtb;
    if(strcmpi(tam2,"hvyeu") == 0) cin>>ds[i].sohvy;
    if(strcmpi(tam2,"canhcao") == 0) cin>>ds[i].canhcao;
    if(strcmpi(tam2,"khientrach") == 0) cin>>ds[i].khientrach;
    if(strcmpi(tam2,"thidua") == 0) gets(ds[i].thidua);
    cout<<"Ban co muon sua thong tin nao khac khong ? <y/n> ";cin>>tl;
    if(tl == 'y') goto re;
    else
    {
        f=fopen("DL.DAT","wb");
        for(i=1;i<so;i++) fwrite(&ds[i],sizeof(LOP),1,f);
        fclose(f);
        getch();
        menu();
    }
}

void case6(void)
{
    char tam4[10];
    int tt;
    system("cls");
    docf();
    cout<<"Nhap TEN LOP can sua thong tin: ";cin>>tam4;
    for(i=1;i<so;i++) if(strcmpi(ds[i].tenLop,tam4) == 0) break;
    tieude();
    inra(i);
    cout<<"\nBAN CO CHAC CHAN MUON XOA THONG TIN CUA LOP ? < Nhap 1 la CO | 2 la KHONG > ";cin>>tt;
    if(tt == 1)
    {
        for(j=i;j<so-1;j++) ds[j]=ds[j+1];
        cout<<"\nXOA THANH CONG!";
        f=fopen("DL.DAT","wb");
        for(i=1;i<so-1;i++) fwrite(&ds[i],sizeof(LOP),1,f);
        fclose(f);
        getch();
        menu();
    }
    else {getch();system("cls");menu();}
}

void case7(void)
{
    system("cls");
    docf();
    sapxep(1);
    tieude();
    for(i=1;i<so;i++) inra(i);
    getch();
    menu();
}

void case8(void)
{
    system("cls");
    docf();
    sapxep(2);
    tieude();
    for(i=1;i<so;i++) inra(i);
    getch();
    menu();
}

void case9(void)
{
    system("cls");
    docf();
    sapxep(3);
    tieude();
    for(i=1;i<so;i++) inra(i);
    getch();
    menu();
}

void case10(void)
{
    system("cls");
    docf();
    tieude();
    for(i=1;i<so;i++) if(strcmpi(ds[i].thidua,"XUAT SAC") == 0) inra(i);
    getch();
    menu();
}

void case11(void)
{
    system("cls");
    docf();
    tieude();
    for(i=1;i<so;i++) if(strcmpi(ds[i].thidua,"TIEN TIEN") == 0) inra(i);
    getch();
    menu();
}

void menu(void)
{
    int m;
    cout<<"\n*******************************************************";
    cout<<"\n*              HE THONG QUAN LY CAC LOP               *";
    cout<<"\n*                                                     *";
    cout<<"\n*  QUAN LY LOP                                        *";
    cout<<"\n*  1. Xem danh sach cac lop                           *";
    cout<<"\n*  2. Xem thong tin cua lop                           *";
    cout<<"\n*  3. Xem thong tin cua tat ca cac lop                *";
    cout<<"\n*  4. Nhap them 1 lop                                 *";
    cout<<"\n*  5. Sua thong tin lop                               *";
    cout<<"\n*  6. Xoa thong tin 1 lop                             *";
    cout<<"\n*                                                     *";
    cout<<"\n*                                                     *";
    cout<<"\n*  SAP XEP                                            *";
    cout<<"\n*  7. Theo ten lop                                    *";
    cout<<"\n*  8. Theo so hoc vien kha                            *";
    cout<<"\n*  9. Theo so hoc vien gioi                           *";
    cout<<"\n*                                                     *";
    cout<<"\n*                                                     *";
    cout<<"\n*  TIM KIEM                                           *";
    cout<<"\n*  10. Cac lop co thi dua XUAT SAC                    *";
    cout<<"\n*  11. Cac lop co thi dua TIEN TIEN                   *";
    cout<<"\n*                                                     *";
    cout<<"\n*                                                     *";
    cout<<"\n*  THOAT KHOI CHUONG TRINH                            *";
    cout<<"\n*  0. Thoat khoi chuong trinh                         *";
    cout<<"\n*                                                     *";
    cout<<"\n*******************************************************";
    cout<<"\n\nLua chon muc tuong ung: < 0 -> 10 > ";cin>>m;
    switch(m)
    {
        case 0: getch();break;
        case 1: case1();break;
        case 2: case2();break;
        case 3: case3();break;
        case 4: case4();break;
        case 5: case5();break;
        case 6: case6();break;
        case 7: case7();break;
        case 8: case8();break;
        case 9: case9();break;
        case 10: case10();break;
        case 11: case11();break;

        default: cout<<"Gia tri nhap khong hop le!";
    }
}

int main()
{
    menu();
    getch();
}






