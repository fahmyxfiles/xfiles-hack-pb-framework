void DrawPlayerBone(int Index, DWORD Color)
{
	DrawBone(Index,7,6,Color);//Kepala - leher
	DrawBone(Index,6,5,Color);// Leher - Dada
	DrawBone(Index,5,4,Color);// Dada - perut
	DrawBone(Index,4,2,Color);// Perut - pantat
	DrawBone(Index,2,0,Color);// Perut - root
	DrawBone(Index,6,11,Color);//Tangan kanan
	DrawBone(Index,6,10,Color);//tangan kiri
	DrawBone(Index,0,13,Color);//Paha kanan
	DrawBone(Index,0,12,Color);//Paha kiri
	DrawBone(Index,13,15,Color);//Lutut kiri
	DrawBone(Index,12,14,Color);//Lutut kanan
	DrawBone(Index,15,9,Color);//telapak kaki kiri
	DrawBone(Index,14,8,Color);//telapak kaki kanan
}


