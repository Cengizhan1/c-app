#include <stdio.h>
#include <stdlib.h>

struct
{
    int seferS;
    int s;
}siraTutucu;
struct otobus
{
  int koltuk;
  char model[20];
  int otobusNo;
  int personelSayisi;
}otobusDizi[10];
struct koltukDoluluk
{
int koltukMatris[4][15];

}koltukDoluluk;

struct seferler
{
  int seferNo;
  int kullanilanOtobus;
  int otobusKoltuksayisi;
  int bSaati;
  int vSaati;
  char bSehri[20];
  char vSehi[20];
  int istenenHasilat;
  int ucret;
}sefer[10];
struct rezervasyon
{
    int rezNo;
    char ad[20];
    char soyAd[20];
    int koltukNo;
    int seferId;
}rez[10];
int sira=0,seferSira=0,rezSira=0;
int main()
{
int k=1;
for(int i=0;i<15;i++)
{
    for(int j=0;j<4;j++)
    {
        koltukDoluluk.koltukMatris[j][i]=k;
        k++;
    }
}
    anaMenu();


}
void anaMenu()
{

    int secim;
    printf("\n\n\t\tAna menu");
    printf("\n\n\t\t1. Firma Girisi");
    printf("\n\t\t2. Yolcu Girisi");
    printf("\n\t\t3. Cikis");
    printf("\n\n\t\tDevam etmek istediginiz kismin solundaki sayiyi giriniz : ");
    scanf("%d",&secim);

    if(secim==1) firmaMenu();
    if(secim==2) yolcuMenu();
    if(secim==3){
        printf("\n\n\t\tProgram basari ile sonlandirilmistir !!!\n\n");
        exit(EXIT_SUCCESS);
    }
    else{
        printf("\n\n\t\tHatali tuslama yaptiniz !!! dogru tusa bastiginiza emin olun");
        anaMenu();
    }



}
void firmaMenu()
{
    int secim2;

    printf("\n\n\n\t\tFirma menu");
    printf("\n\n\t\t1. Otobus ekle");
    printf("\n\t\t2. Sefer bilgisi ekle");
    printf("\n\t\t3. Sefer ,koltuk bilgisi");
    printf("\n\t\t4. Bir ust menuye don");
    printf("\n\n\t\tDevam etmek istediginiz kismin solundaki sayiyi giriniz : ");
    scanf("%d",&secim2);



    if(secim2==1) {
        sira = sira+1;
        siraTutucu.s=sira;
        otobusEkle(sira);
    }

    if(secim2==2)
    {
        if( sira==0){
        printf("\n\n\n\t\tKullanilabilir otobus yok lutfen once otobus ekleyin !!!");
        firmaMenu();
        }
            seferSira=seferSira+1;
            siraTutucu.seferS=seferSira;
            seferEkle(seferSira,sira);
    }

    if(secim2==3)
    {
        if( seferSira==0){
        printf("\n\n\n\t\tKullanilabilir sefer yok lutfen once sefer ekleyin !!!");
        firmaMenu();
        }
            seferListele(seferSira);
    }
    if(secim2==4)
    {
        anaMenu();
    }
    else {
         printf("\n\n\n\t\tHatali tuslama yaptiniz !!!");
         firmaMenu();
    }





}
void yolcuMenu()
{
    int secim3,seferNoKontrol,kontrolS=0,guncelSefer;
    printf("\n\n\n\t\tYolcu menu");
    printf("\n\n\t\t1. Seferleri listele");
    printf("\n\t\t2. Rezervasyon yap");
    printf("\n\t\t3. Rezervasyon goster");
    printf("\n\t\t4. Bir ust menuye don");
    printf("\n\n\t\tDevam etmek istediginiz kismin solundaki sayiyi giriniz : ");
    scanf("%d",&secim3);

    if(secim3==1) {
        printf("\n\n\n\t\tSefer no | Baslangic Saati | Varis Saati | Baslangic sehri | Varis sehri | Koltuk ucreti |\n");
        for(int i=0;i<siraTutucu.seferS;i++)
        {
        printf(    "\n\t\t%d       | %d            | %d        | %s           | %s       | %d            |",sefer[i].seferNo,sefer[i].bSaati,
                   sefer[i].vSaati,sefer[i].bSehri,sefer[i].vSehi,sefer[i].ucret);
        }

        printf("\n\n\n\t\t Devam etmek icin herhangi bir tusa basiniz : ");
        getch();
        yolcuMenu();
    }

    if(secim3==2)
    {
        while(kontrolS==0)
        {
           printf("\n\n\n\t\t Devam etmek icin sefer numarasini giriniz : ");
           scanf("%d",&seferNoKontrol);
            for(int i=0;i<=siraTutucu.seferS;i++)
            {
              if(seferNoKontrol==sefer[i].seferNo||seferNoKontrol==0)
               {
                  kontrolS++;
                  guncelSefer=i;

               }
            }
            if(kontrolS==0)
               {
                  printf("\n\n\n\t\t Hatali giris yaptiniz lutfen tekrar giriniz : ");
               }

        }

        rezSira=rezSira+1;
        rezervasyonYap(rezSira,guncelSefer);
    }

    if(secim3==3)
    {
        int rNo;
        printf("\n\n\n\t\t Rezervasyon numarasini giriniz : ");
        scanf("%d",&rNo);

        for(int i=0;i<rezSira;i++)
        {
            if(rNo==rez[i].rezNo){

                printf("\n\n\n\t\t Rezervasyon no : %d",rez[i].rezNo);
                printf("\n\n\n\t\t AD : %s",rez[i].ad);
                printf("\n\n\n\t\t SOYAD : %s",rez[i].soyAd);
                printf("\n\n\n\t\t Koltuk no : %d",rez[i].koltukNo);
                printf("\n\n\n\t\t Kalkis sehri : %s",sefer[rez[i].seferId].bSehri);
                printf("\n\n\n\t\t Varis sehri : %s",sefer[rez[i].seferId].vSehi);
                printf("\n\n\n\t\t Kalkis saati : %d",sefer[rez[i].seferId].bSaati);
                printf("\n\n\n\t\t Varis saati : %d",sefer[rez[i].seferId].vSaati);
                yolcuMenu();

            }

        }

    }
    if(secim3==4)
    {
        anaMenu();
    }
    else {
         printf("\n\n\n\t\tHatali tuslama yaptiniz !!!");
         firmaMenu();
    }
}
void rezervasyonYap(int a,int k)
{
    a--;
    printf("\n\n");

    int koltukKontrol=sefer[k].otobusKoltuksayisi/4;
    int kontrolK=0;


    rez[a].seferId=k;
    for(int i=0;i<koltukKontrol;i++)
    {
        for(int j=0;j<4;j++)
       {
        printf("\t\t\t\t");
        printf("|%d| ",koltukDoluluk.koltukMatris[j][i]);
        j++;
        printf("|%d|",koltukDoluluk.koltukMatris[j][i]);
        j++;
        printf("   ");
        printf("|%d| ",koltukDoluluk.koltukMatris[j][i]);
        j++;
        printf("|%d|",koltukDoluluk.koltukMatris[j][i]);
       }

    printf("\n");
}

while(kontrolK==0)
        {
            printf("\n\n\n\t\t Sectiginiz koltugu tuslayiniz(0 dolu koltuklari gosterir!) : ");
            scanf("%d",&rez[a].koltukNo);

            for(int i=0;i<koltukKontrol;i++)
                {
                 for(int j=0;j<4;j++)
                    {
                    if(koltukDoluluk.koltukMatris[j][i]==rez[a].koltukNo)
                      {

                        koltukDoluluk.koltukMatris[j][i]=0;
                        kontrolK++;

                      }
                    }
                }

        }





    printf("\n\n");
    for(int i=0;i<koltukKontrol;i++)
{
    for(int j=0;j<4;j++)
    {
        printf("\t\t\t\t");
        printf("|%d| ",koltukDoluluk.koltukMatris[j][i]);
        j++;
        printf("|%d|",koltukDoluluk.koltukMatris[j][i]);
        j++;
        printf("   ");
        printf("|%d| ",koltukDoluluk.koltukMatris[j][i]);
        j++;
        printf("|%d|",koltukDoluluk.koltukMatris[j][i]);
    }
    printf("\n");
}





    printf("\n\n\n\t\t Ad : ");
    scanf("%s",rez[a].ad);

    printf("\n\n\n\t\t Soy Ad : ");
    scanf("%s",rez[a].soyAd);

    srand(time(NULL));
    rez[a].rezNo=rand()%89999999+10000000;

    printf("\n\n\n\t\t Rezervasyon numaranizi lutfen saklayiniz : %d",rez[a].rezNo);

    yolcuMenu();

}
void otobusEkle(int x)
{
   x--;

   int personel=2;
   char model[20];

   printf("\n\n\n\t\tOtobusun koltuk sayisi :");
   scanf("%d",&otobusDizi[x].koltuk);

   printf("\n\n\n\t\tOtobusun modeli :");
   scanf("%s",otobusDizi[x].model);

   if(otobusDizi[x].koltuk<=30) {
        personel=3;}

   otobusDizi[x].otobusNo=x+1;
   otobusDizi[x].personelSayisi=personel;


   firmaMenu();

}
void seferEkle(int y,int k)
{
    y--;

    printf("\n\n\n\t\tKullanilabilir otobüsler >>>");
    for(int j=0;j<k;j++)
    {
       printf("\n\n\n\t\tYolcu menu");
       printf("\n\n\t\t Otobus numarasi : %d",otobusDizi[j].otobusNo);
       printf("\n\t\t Koltuk Sayisi : %d",otobusDizi[j].koltuk);
       printf("\n\t\t Model : %s",otobusDizi[j].model);
       printf("\n\t\t Personel sayisi : %d",otobusDizi[j].personelSayisi);
    }

    seferKod(y);

    printf("\n\n\n\t\tKullanmak istediginiz otobusun numarasini giriniz :");
    scanf("%d",&sefer[y].kullanilanOtobus);

    seferBsaat(y);

    int otoSira=seferVsaat(y,k);

    seferKonum(y);

    seferHasilat(y);

    seferUcret(y,otoSira);

    firmaMenu();

}
void seferListele(int y)
{
   int numara,seferTutucu,k;

   for(int i=0;i<y;i++)
   {
       numara=i+1;
       printf("\n\n\t\t %d. sefer no : %d",numara,sefer[i].seferNo);
   }
   printf("\n\n\n\t\t Ayrintili bilgi gormek istediginiz sefer nnumarasini giriniz : ");
   scanf("%d",&seferTutucu);

   for(int i=0;i<y;i++)
   {
       if(seferTutucu==sefer[i].seferNo)
       {
           k=i;
       }
   }
   printf("\n\n\t\t Sefer no : %d",sefer[k].seferNo);
   printf("\n\n\t\t Kullaninlan otobus no : %d",sefer[k].kullanilanOtobus);
   printf("\n\n\t\t Baslangic saati : %d",sefer[k].bSaati);
   printf("\n\n\t\t Varis saati : %d",sefer[k].vSaati);
   printf("\n\n\t\t Baslangic sehri : %s",sefer[k].bSehri);
   printf("\n\n\t\t Varis sehri : %s",sefer[k].vSehi);
   printf("\n\n\t\t İstenilen toplam hasilat : %d",sefer[k].istenenHasilat);
   printf("\n\n\t\t Koltuk basi ucret : %d",sefer[k].ucret);

   firmaMenu();
}
void seferUcret(int y,int k)
{

    int koltukSayisi,toplam,kUcret;

    koltukSayisi=otobusDizi[k-1].koltuk;
    toplam=sefer[y].istenenHasilat;

    kUcret=toplam/koltukSayisi;

    sefer[y].ucret=kUcret;
    sefer[y].otobusKoltuksayisi=koltukSayisi;

}
void seferHasilat(int y)
{
    printf("\n\n\n\t\tBu sefer icin istenilen hasilati giriniz :");
    scanf("%d",&sefer[y].istenenHasilat);
}
void seferKonum(int y)
{
    printf("\n\n\n\t\tSefer baslangıc sehrini giriniz :");
    scanf("%s",sefer[y].bSehri);

    printf("\n\n\n\t\tSefer varis sehrini giriniz :");
    scanf("%s",sefer[y].vSehi);

}

int seferVsaat(int y,int k)
{
    int kontrol,kontrol2,sayi1,sayi2,sayac=1,otoSira;

    while(sayac==1)
    {

    printf("\n\n\n\t\tSefer tahmini varis saatini giriniz :");
    scanf("%d",&sefer[y].vSaati);

    kontrol=sefer[y].vSaati-sefer[y].bSaati;



    for(int i=0;i<k;i++)
    {
        if(otobusDizi[i].otobusNo==sefer[y].kullanilanOtobus-1){
          otoSira=i;
        }
    }

    if(kontrol > 400 && otobusDizi[otoSira-1].koltuk < 30)
    {
        printf("\n\n\n\t\tSefer tahmini varis saatini uygun girmediniz. Lutfen sectiginiz otobuse uygun bir saat giriniz!!!");

    }
    else
    {
        sayac--;
    }

    }
    return otoSira;
}
void seferKod(int y)
{
    int hex;
    srand(time(NULL));
    hex = (rand() & 0xff) << 8;

    sefer[y].seferNo=hex;

    printf("\n\n\n\t\tOtomatik atanan sefer no : %d",hex);

}
void seferBsaat(int y)
{
    int kontrol,kontrol2,sayi1,sayi2,sayac=1;

    while(sayac==1)
    {
    sayac--;
    printf("\n\n\n\t\tSefer baslangic saatini giriniz. (orn saat : XX14 dakika kismi her zaman 14 olmalidir!) : ");
    scanf("%d",&sefer[y].bSaati);

    sayi1=sefer[y].bSaati/1000;
    sayi2=(sefer[y].bSaati-(sayi1*1000))/100;
    kontrol=sefer[y].bSaati-(sayi1*1000+sayi2*100);
    kontrol2=sayi1*10+sayi2;
    if(kontrol2>=24)
    {
      printf("\n\n\n\t\tBaslangic saatinin saat kismi 24ten buyuk olamaz!! tekrar giriniz !!!");
      sayac++;
      continue;
    }
    if(kontrol!=14){
    printf("\n\n\n\t\tBaslangic saatinin dakika kismi 14 olmalidir!! tekrar giriniz !!!");
    sayac++;
    }
    }
}

