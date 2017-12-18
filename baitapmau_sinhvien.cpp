#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include <fstream>
#include <string>
#include<math.h>
int i,j,n;

void menu(void);

FILE *f;

using namespace std;

// CAU 1

typedef struct {
    int d1,d2,d3;
} diem;

typedef struct {
    char hova[16],ten[6];
    diem diemkt;
    int dcc,dtd,dthi;
    float dtk;
} hocvien;

hocvien ds[100],tam;

void docf(void)
{
    i=1;
    f=fopen("dl.DAT","rb");
    if(f == NULL) {f=fopen("dl.DAT","wb");fclose(f);}
    f=fopen("dl.DAT","rb");
    while(!feof(f))
    {
        fread(&ds[i],sizeof(hocvien),1,f);
        i++;
    }
    n=i-1;
    fclose(f);
}

void luufi(int j)
{
    f=fopen("dl.DAT","a+b");
    fwrite(&ds[j],sizeof(hocvien),1,f);
    fclose(f);
}

void nhap(int i)
{
    char tl = 'y';
    while(tl == 'y')
    {
    fflush(stdin);
    cout<<"Nhap HO va TEN DEM: ";gets(ds[i].hova);fflush(stdin);
    cout<<"Nhap TEN: ";gets(ds[i].ten);fflush(stdin);
    cout<<"Nhap lan luot diem kiem tra 1, 2 va 3: ";cin>>ds[i].diemkt.d1>>ds[i].diemkt.d2>>ds[i].diemkt.d3;
    cout<<"Nhap lan luot diem chuyen can va diem thai do: ";cin>>ds[i].dcc>>ds[i].dtd;
    cout<<"Nhap diem thi ket thuc hoc phan: ";cin>>ds[i].dthi;
    ds[i].dtk=0.7*ds[i].dthi + 0.05*(ds[i].dcc + ds[i].dtd) + 0.2*(ds[i].diemkt.d1 + ds[i].diemkt.d2 + ds[i].diemkt.d3)/3; //Tinh diem tong ket hoc phan
    cout<<"\nBan co muon nhap tiep khong ? ";cin>>tl;
    luufi(i);
    i++;
    }
}

void cau1(void)
{
    system("cls");
    nhap(n);
    getch();
    system("cls");
    menu();
}

// CAU 2

void tieude(void)
{
    cout<<"\n|STT|             HO|     TEN|   D1|   D2|   D3|  DIEMCC|  DIEMTD|  DIEMHP|  DIEMTK| THUHANG|\n";
}

void xuat(int i)
{
    cout<<endl<<setw(4)<<i<<'|'<<setw(15)<<ds[i].hova<<'|';
    cout<<setw(8)<<ds[i].ten<<'|'<<setw(5)<<ds[i].diemkt.d1<<'|'<<setw(5)<<ds[i].diemkt.d2<<'|'<<setw(5)<<ds[i].diemkt.d3<<'|';
    cout<<setw(8)<<ds[i].dcc<<'|'<<setw(8)<<ds[i].dtd<<'|'<<setw(8)<<ds[i].dthi<<'|'<<setw(8)<<setprecision(2)<<ds[i].dtk<<'|';
}

void cau2(void)
{
    system("cls");
    tieude();
    for(i=1;i<n;i++) xuat(i);
    getch();
    menu();
}

// CAU 3

void cau3(void)
{
    system("cls");
    tieude();
    float mi=ds[1].dtk;
    for(i=2;i<n;i++) if(ds[i].dtk < mi) mi=ds[i].dtk;
    for(i=1;i<n;i++)
    {
        if(ds[i].dtk  ==  mi) xuat(i);
    }
    getch();
    menu();
}

// CAU 4

void sapxep(void)
{
    for(i=1;i<n;i++)
        for(j=i+1;j<n;j++)
            if(ds[i].dtk<ds[j].dtk)
            {
                tam=ds[i];
                ds[i]=ds[j];
                ds[j]=tam;
            }
}

void cau4(void)
{
    system("cls");
    sapxep();
    cout<<"Danh sach da sap xep: \n";
    tieude();
    for(i=1;i<n;i++) xuat(i);
    getch();
    menu();
}

// CAU 5

int thuhang(int k)
{
    int th[n-1];
    th[1]=1;
    for(i=1;i<=k;i++)
    {
        if(i == 1) break;
        if(ds[i].dtk < ds[i-1].dtk) th[i]=i;
        else th[i]=th[i-1];
    }
    return th[k];
}

void cau5(void)
{
    int t,b[20];
    system("cls");
    sapxep();
    tieude();
    for(i=1;i<n;i++)
    {
        xuat(i);
        cout<<setw(8)<<thuhang(i)<<'|';
    }
    getch();
    menu();
}

int main()
{
    menu();
}

void menu(void)
{
    docf();
    int tl,e;
    cout<<"\n\n[1].Nhap them sinh vien";
    cout<<"\n\n[2].Xem danh sach";
    cout<<"\n\n[3].Tim hoc vien co DIEM TONG KET thap nhat";
    cout<<"\n\n[4].Sap xep va xem danh sach theo DIEM TRUNG BINH giam dan";
    cout<<"\n\n[5].Xac dinh thu hang cua sinh vien";
    cout<<"\n\n[0].Thoat khoi chuong trinh";
    cout<<"\n\nCHON MUC: ";
    fflush(stdin);
    tl=getch();
    switch(tl)
    {
    case 48: cout<<"Nhap 0 lan nua de thoat: "; cin>>e; if(e == 0) break;
    case 49: cau1();break;
    case 50: cau2();break;
    case 51: cau3();break;
    case 52: cau4();break;
    case 53: cau5();break;

    default: cout<<"Nhap tu 0 den 5 !!! ";
    }
}





