void DrawStringC(LPD3DXFONT pFont, long x, long y, D3DCOLOR fontColor, char *text, ...)
{
	D3DCOLOR BordColor = BLACK;
    RECT rct;
    rct.left     = x - 1;
    rct.right    = x + 1;
    rct.top      = y - 1 ;
    rct.bottom    = y + 1;
    if(!text) { return; }
    va_list va_alist;
    char logbuf[1000] = {0};
    va_start (va_alist, text);
    _vsnprintf(logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
    va_end (va_alist);
    RECT FontRect = { x, y, x, y };
    pFont->DrawTextA(NULL, logbuf, -1, &rct, DT_NOCLIP + DT_CENTER, fontColor);
	
}

 void DrawLine  ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, DWORD Color)
{	
	DWORD HPcol = GREEN;  // Deklarasi Health Protection Color 

	D3DXVECTOR2 vLine[ 2 ]; // 2 Poin
	g_pLine->SetAntialias( true ); // Set Tepi

	g_pLine->SetWidth( dwWidth ); // Lebar Dari Line
	g_pLine->Begin();

		vLine[ 0 ][ 0 ] = Xa; // Jadikan Point Menjadi Array
		vLine[ 0 ][ 1 ] = Ya;
		vLine[ 1 ][ 0 ] = Xb;
		vLine[ 1 ][ 1 ] = Yb;

	g_pLine->Draw( vLine, 2, Color ); // Draw Garis , Jumlah Garis , Warna Garis 
	g_pLine->End(); // Selesai
}

 void DrawLineColor  ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, DWORD Color)
{	
	D3DXVECTOR2 vLine[ 2 ]; // 2 Poin
	g_pLine->SetAntialias( true ); // Set Tepi

	g_pLine->SetWidth( dwWidth ); // Lebar Dari Line
	g_pLine->Begin();

		vLine[ 0 ][ 0 ] = Xa; // Jadikan Point Menjadi Array
		vLine[ 0 ][ 1 ] = Ya;
		vLine[ 1 ][ 0 ] = Xb;
		vLine[ 1 ][ 1 ] = Yb;

	g_pLine->Draw( vLine, 2, Color ); // Draw Garis , Jumlah Garis , Warna Garis 
	g_pLine->End(); // Selesai
}
 void DrawString(LPD3DXFONT pFont,int x, int y, DWORD color, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	
	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

 
void FillRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
if( w < 0 )w = 1;
if( h < 0 )h = 1;
if( x < 0 )x = 1;
if( y < 0 )y = 1;
 
D3DRECT rec = { x, y, x + w, y + h };
pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

void DrawBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice )
{
FillRGB( x, (y + h - px), w, px, BorderColor, pDevice );
FillRGB( x, y, px, h, BorderColor, pDevice );
FillRGB( x, y, w, px, BorderColor, pDevice );
FillRGB( (x + w - px), y, px, h, BorderColor, pDevice );
}


void Draw3DBox(int HeadX,int HeadY,int bottomX,int bottomY,float Distance_Player,DWORD Color)
{
float drawW = 300/Distance_Player;
float drawW2 = 150/Distance_Player;
float drawW3 = 75/Distance_Player;
DrawLine(bottomX-drawW,bottomY,bottomX+drawW,bottomY,1,Color);
DrawLine(HeadX-drawW,HeadY,HeadX+drawW,HeadY,1,Color);
DrawLine(HeadX-drawW,HeadY,bottomX-drawW,bottomY,1,Color);
DrawLine(HeadX+drawW,HeadY,bottomX+drawW,bottomY,1,Color);
DrawLine(HeadX-drawW2,HeadY-drawW3,bottomX-drawW2,bottomY-drawW3,1,Color);
DrawLine(bottomX-drawW,bottomY,bottomX-drawW2,bottomY-drawW3,1,Color);
DrawLine(HeadX-drawW,HeadY,HeadX-drawW2,HeadY-drawW3,1,Color);
DrawLine((HeadX+drawW)+drawW2,HeadY-drawW3,(bottomX+drawW)+drawW2,bottomY-drawW3,1,Color);
DrawLine(bottomX+drawW,bottomY,(bottomX+drawW)+drawW2,bottomY-drawW3,1,Color);
DrawLine(HeadX+drawW,HeadY,(HeadX+drawW)+drawW2,HeadY-drawW3,1,Color);
DrawLine(HeadX-drawW2,HeadY-drawW3,(HeadX+drawW)+drawW2,HeadY-drawW3,1,Color);
DrawLine(bottomX-drawW2,bottomY-drawW3,(bottomX+drawW)+drawW2,bottomY-drawW3,1,Color);

}

void DrawESPLine ( long Xa, long Ya, long Xb, long Yb, DWORD dwWidth, D3DCOLOR Color )
{
	D3DXVECTOR2 vLine[ 2 ];
	g_pLine->SetAntialias( true );

	g_pLine->SetWidth( (float)dwWidth );
	g_pLine->Begin();

	vLine[ 0 ][ 0 ] = (float)Xa;
	vLine[ 0 ][ 1 ] = (float)Ya;
	vLine[ 1 ][ 0 ] = (float)Xb;
	vLine[ 1 ][ 1 ] = (float)Yb;

	g_pLine->Draw( vLine, 2, Color );
	g_pLine->End();
}
void HealthBar(float x, float y, float Health, LPDIRECT3DDEVICE9 pDevice)
{
	DWORD HPcol = GREEN;
	if (Health < 90)HPcol = YELLOW;
	if (Health < 80) HPcol = ORANGE;
	if (Health < 40) HPcol = RED;
	if(Health > 100)Health = 100;
	DrawBorder(x-1,y-1,52,5,1,BLACK,pDevice );
	FillRGB(x,y,Health/2,3,HPcol,pDevice );
}
