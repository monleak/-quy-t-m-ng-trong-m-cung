/*
Ý TƯỞNG:
viết 1 mảng 2 chiều để nhận vào bản đồ
tạo 2 biến cấu trúc để nhận vào đầu vào đầu ra
1 cấu trúc nhận giá trị của ô (có đánh dấu bôi đen)
xét tất cả các nhánh con, nếu có giá trị bằng với ô kết thúc thì báo có, else báo không*/
//------------------------------------------------------------------------------------
// CODE:
#include <stdio.h>
#include <stdlib.h>

typedef struct _giatri
{
	int toadox;
	int toadoy;
	int giatri;
	int danhdau;
}giatri;

static giatri bando[6][6]; //khai báo mảng và khởi tạo giá trị 0 cho các phần tử

int kiemtra=0;

void timduong(int x, int y, int daurax, int dauray) //hàm tìm tất cả các nhánh con
{
	bando[x][y].danhdau=1;
	if(x==daurax&&y==dauray) kiemtra=1;
	if((x<5)&&(bando[x+1][y].danhdau!=1)&&(bando[x+1][y].giatri==1))
	{
		timduong(x+1,y,daurax,dauray);
	}
	if((x>0)&&(bando[x-1][y].danhdau!=1)&&(bando[x-1][y].giatri==1))
	{
		timduong(x-1,y,daurax,dauray);
	}
	if((y<5)&&(bando[x][y+1].danhdau!=1)&&(bando[x][y+1].giatri==1))
	{
		timduong(x,y+1,daurax,dauray);
	}
	if((y>0)&&(bando[x][y-1].danhdau!=1)&&(bando[x][y-1].giatri==1))
	{
		timduong(x,y-1,daurax,dauray);
	}
}
int main()
{
	FILE* data = fopen("data.txt","r");	
	static giatri dauvao;
	static giatri daura;
	//nhận đầu ra đầu vào và in ra màn hình
	fscanf(data,"%d %d",&dauvao.toadox,&dauvao.toadoy);
	printf("Dau vao: (%d,%d)\n", dauvao.toadox,dauvao.toadoy);
	fscanf(data,"%d %d",&daura.toadox,&daura.toadoy);
	printf("Dau ra: (%d,%d)\n", daura.toadox,daura.toadoy);
	int x=0,y=0;
	//vòng lặp để nhận các giá trị của bản đồ đồng thời in bản đồ ra màn hình
	printf("\nBAN DO:\n");
	while(fscanf(data,"%1d",&bando[x][y].giatri)!=EOF)
	{
		printf("%d", bando[x][y].giatri);
		bando[x][y].toadox=x;
		bando[x][y].toadoy=y;
		++x;
		if(x==6)
		{
			++y;
			printf("\n");
			x=0;
		}
	}
	timduong(dauvao.toadox,dauvao.toadoy,daura.toadox,daura.toadoy);
	if(kiemtra)
		printf("\nKET QUA: Co duong di\n");
	else
		printf("\nKET QUA: Khong co duong di\n");
	return 0;
}
