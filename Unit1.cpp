//---------------------------------------------------------------------------
//Created by Cezary
//Pobrane obrazy ze �r�d�a: focus.pl oraz freepik.com


#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int do_wygranej=13;

int x=-8, y=-8;
bool kolizja(TImage * pilka, TImage * cegla)
{
        if ((pilka -> Left >= cegla -> Left - pilka -> Width) &&
        (pilka -> Left <= cegla -> Left + cegla -> Width) &&
        (pilka -> Top >= cegla -> Top - pilka -> Height) &&
        (pilka -> Top <= cegla -> Top + cegla -> Height))
        {
                return true;
        }
        else return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
        MediaPlayer1 -> Play();

        ball -> Left+=x;
        ball -> Top+=y;

        //odbij od lewej sciany
        if (ball -> Left - 5 <= tlo -> Left) x = -x;

        //odbij od gornej sciany
        if (ball -> Top - 5 <= tlo -> Top) y = -y;

        //odbij od prawej sciany
        if (ball -> Left + ball -> Width + 5 >= tlo -> Width) x = -x;

        //skucha
        if (ball -> Top >= paddle -> Top + paddle -> Height + 15)
        {
                Timer_pilka -> Enabled = false;
                ball -> Visible = false;
                Button1 -> Caption = "You lose! Once again?";
                Button1 -> Visible = true;
        }
        else if (((ball -> Left > paddle -> Left - ball -> Width / 2) && (ball -> Left < paddle -> Left + paddle -> Width)) &&
        (ball -> Top + ball -> Height > paddle -> Top))
        {
                if (y > 0) y = -y;
        }

        if (do_wygranej<=0)
        {
                Timer_pilka -> Enabled = false;
                ball -> Visible = false;
                Button1 -> Caption = "You won! Once again?";
                Button1 -> Visible = true;
        }

        //blok1
        if ((kolizja(ball,Image1) == true) && (Image1 -> Visible == true))
        {
                x = -x; y = -y;
                Image1 -> Visible = false;
                do_wygranej--;
        }

        //blok2
        if ((kolizja(ball,Image2) == true) && (Image2 -> Visible == true))
        {
                x = -x; y = -y;
                Image2 -> Visible = false;
                do_wygranej--;
        }

        //blok3
        if ((kolizja(ball,Image3) == true) && (Image3 -> Visible == true))
        {
                x = -x; y = -y;
                Image3 -> Visible = false;
                do_wygranej--;
        }

        //blok4
        if ((kolizja(ball,Image4) == true) && (Image4 -> Visible == true))
        {
                x = -x; y = -y;
                Image4 -> Visible = false;
                do_wygranej--;
        }

        //blok5
        if ((kolizja(ball,Image5) == true) && (Image5 -> Visible == true))
        {
                x = -x; y = -y;
                Image5 -> Visible = false;
                do_wygranej--;
        }
        //blok6
        if ((kolizja(ball,Image6) == true) && (Image6 -> Visible == true))
        {
                x = -x; y = -y;
                Image6 -> Visible = false;
                do_wygranej--;
        }

        //blok7
        if ((kolizja(ball,Image7) == true) && (Image7 -> Visible == true))
        {
                x = -x; y = -y;
                Image7 -> Visible = false;
                do_wygranej--;
        }

        //blok8
        if ((kolizja(ball,Image8) == true) && (Image8 -> Visible == true))
        {
                x = -x; y = -y;
                Image8 -> Visible = false;
                do_wygranej--;
        }

        //blok9
        if ((kolizja(ball,Image9) == true) && (Image9 -> Visible == true))
        {
                x = -x; y = -y;
                Image9 -> Visible = false;
                do_wygranej--;
        }

        //blok10
        if ((kolizja(ball,Image10) == true) && (Image10 -> Visible == true))
        {
                x = -x; y = -y;
                Image10 -> Visible = false;
                do_wygranej--;
        }

        //blok11
        if ((kolizja(ball,Image11) == true) && (Image11 -> Visible == true))
        {
                x = -x; y = -y;
                Image11 -> Visible = false;
                do_wygranej--;
        }

        //blok12
        if ((kolizja(ball,Image12) == true) && (Image12 -> Visible == true))
        {
                x = -x; y = -y;
                Image12 -> Visible = false;
                do_wygranej--;
        }

        //blok13
        if ((kolizja(ball,Image13) == true) && (Image13 -> Visible == true))
        {
                x = -x; y = -y;
                Image13 -> Visible = false;
                do_wygranej--;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewoTimer(TObject *Sender)
{
        if (paddle -> Left > 10) paddle -> Left -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawoTimer(TObject *Sender)
{
        if (paddle -> Left + paddle -> Width < tlo -> Width - 10) paddle -> Left += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_LEFT) lewo -> Enabled = true;
        if (Key == VK_RIGHT) prawo -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_LEFT) lewo -> Enabled = false;
        if (Key == VK_RIGHT) prawo -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ball -> Left = 50;
        ball -> Top = 50;

        ball -> Visible = true;
        x = -8; y = -8;

        Timer_pilka -> Enabled = true;
        Button1 -> Visible = false;

        do_wygranej = 13;

        Image1 -> Visible = true; Image2 -> Visible = true; Image3 -> Visible = true;
        Image4 -> Visible = true; Image5 -> Visible = true; Image6 -> Visible = true;
        Image7 -> Visible = true; Image8 -> Visible = true; Image9 -> Visible = true;
        Image10 -> Visible = true; Image11 -> Visible = true; Image12 -> Visible = true;
        Image13 -> Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        MediaPlayer1 -> FileName = "play.mp3";
        MediaPlayer1 -> Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        MediaPlayer1 -> Close();
}
//---------------------------------------------------------------------------

