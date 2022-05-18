float DistanceBetweenVector( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB )
{
        return sqrt( ( ( VecA.x - VecB.x ) * ( VecA.x - VecB.x ) ) +
                 ( ( VecA.y - VecB.y ) * ( VecA.y - VecB.y ) ) +
                 ( ( VecA.z - VecB.z ) * ( VecA.z - VecB.z ) ) );
}

int GetTeam(int MyT)
{

	if(MyT % 2 == 0)return 0;
	else return 1;
	return -1;
}
bool GetUserBone(D3DXVECTOR3 &Out,int BoneIndex, int CharaIndex)
{

	if( pGameCharaManager->getCharaByNetIdx(CharaIndex) && 
		pGameCharaManager->getCharaByNetIdx(CharaIndex)->getGameCharaBoneContext() )
	{
		Out = pGameCharaManager->getCharaByNetIdx(CharaIndex)->getGameCharaBoneContext()->getBonePosition(BoneIndex);
		return true;
	}
	return false;
}

D3DXVECTOR3 GetCamera()
{
	D3DXVECTOR3 out;
    D3DXMATRIX  iViewMat;

	D3DXMatrixInverse(&iViewMat,0,pRenderContext->GetViewMatrix());

	out.x = iViewMat._41;
	out.y = iViewMat._42;
	out.z = iViewMat._43;

	return out;
}
#define M_PI 3.141592654
double radians (double d) { 
return d * M_PI / 180; 
} 
double degrees (double r) { 
return r * 180/ M_PI; 
} 

void VectorAngles( const float* forward, float* angles )
{
	float tmp, yaw, pitch;

	if( forward[2] == 0 && forward[0] == 0 )
	{
		yaw = 0;

		if( forward[2] > 0 )
			pitch = 90;
		else
			pitch = 270;
	}
	else 
	{
		yaw = ( atan2( forward[2], -forward[0] ) * 180 / M_PI )-90;

		if( yaw < 0 )
			yaw += 360;

		tmp = sqrt( forward[0] * forward[0] + forward[2] * forward[2] );
		pitch = ( atan2( forward[1], tmp) * 180 / M_PI );

		if( pitch < 0 )
			pitch += 360;
	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;
}
void GetAngleToTarget(D3DXVECTOR3 vTargetPos, D3DXVECTOR3 vCameraPos, D3DXVECTOR3& vAngles)
{
	D3DXVECTOR3 vDelta;
	vDelta.x = vTargetPos.x - vCameraPos.x;
	vDelta.y = vTargetPos.y - vCameraPos.y;
	vDelta.z = vTargetPos.z - vCameraPos.z;

	VectorAngles( (float*)&vDelta, (float*)&vAngles );

	if( vAngles.x > 180.0f )          
		vAngles.x  -= 360.0f; 
	else if( vAngles.x < -180.0f )    
		vAngles.x   += 360.0f; 

	if( vAngles.y > 180.0f )            
		vAngles.y     -= 360.0f; 
	else if( vAngles.y < -180.0f )      
		vAngles.y    += 360.0f; 
}
void SetLocalPawnAimTarget(D3DXVECTOR3 AimTarget){
	D3DXVECTOR3 vAngle;
	GetAngleToTarget(AimTarget,GetCamera(),vAngle);

	pGameCharaManager->getLocalChara()->getGameCharaBoneContext()->setCrosshairYaw(radians(vAngle[1]));
	pGameCharaManager->getLocalChara()->getGameCharaBoneContext()->setCrosshairPitch(radians(vAngle[0]));
}


void DrawBone(int CharaIndex, int BoneIndexStart, int BoneIndexEnd, DWORD Color)
{
	D3DXVECTOR3 OnWorldA,OnScreenA;
	D3DXVECTOR3 OnWorldB,OnScreenB;
	if(GetUserBone(OnWorldA,BoneIndexStart,CharaIndex) && pRenderContext->WorldToScreen(OnWorldA,OnScreenA,npDevice) && GetUserBone(OnWorldB,BoneIndexEnd,CharaIndex) && pRenderContext->WorldToScreen(OnWorldB,OnScreenB,npDevice))
	{
		DrawLineColor(OnScreenA.x,OnScreenA.y,OnScreenB.x,OnScreenB.y,1,Color);
	}
}
bool bAimState = false;

bool GetAimAssistState()
{
	if(FeatureStruct->GameHack.Assist.Hotkey == 0)return true;
	if(FeatureStruct->GameHack.Assist.HotkeyMode == 0){
		switch(FeatureStruct->GameHack.Assist.Hotkey)
		{
		case 1:
			bAimState = GetKeyboardPressState(DIK_LCONTROL);
			break;
		case 2:
			bAimState = GetKeyboardPressState(DIK_LALT);
			break;
		case 3:
			bAimState = GetKeyboardPressState(DIK_LSHIFT);
			break;
		case 4:
			bAimState = GetKeyboardPressState(DIK_CAPSLOCK);
			break;
		case 5:
			bAimState = GetKeyboardPressState(DIK_TAB);
			break;
		}
	}
	else if (FeatureStruct->GameHack.Assist.Hotkey == 1){
		switch(FeatureStruct->GameHack.Assist.Hotkey)
		{
		case 1:
			if(IsKeyboardKeyDownOnce(DIK_LCONTROL))bAimState = !bAimState;
			break;
		case 2:
			if(IsKeyboardKeyDownOnce(DIK_LALT))bAimState = !bAimState;
			break;
		case 3:
			if(IsKeyboardKeyDownOnce(DIK_LSHIFT))bAimState = !bAimState;
			break;
		case 4:
			if(IsKeyboardKeyDownOnce(DIK_CAPSLOCK))bAimState = !bAimState;
			break;
		case 5:
			if(IsKeyboardKeyDownOnce(DIK_TAB))bAimState = !bAimState;
			break;
		}
	}
	return bAimState;
}