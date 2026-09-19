// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ?preRender@ScreenMotionBlurFilter@@UAE_NAA_NAAW4CustomScenePassModes@@@Z retail 0x000FD4CE (19B).
// Ported from Open-BFME-1 Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DShaderManager.cpp
// (BFME1 0x007D8790, donor-verbatim): copies m_skipRender into skipRender,
// calls startRenderToTexture and returns true. Only the placed body is defined
// here.

enum CustomScenePassModes
{
	CUSTOM_SCENE_PASS_DUMMY = 0
};

class W3DShaderManager
{
public:
	static void startRenderToTexture();
};

class ScreenMotionBlurFilter
{
public:
	virtual bool preRender(bool &skipRender, CustomScenePassModes &scenePassMode);

	char m_pad[0x09];
	bool m_skipRender;
};

bool ScreenMotionBlurFilter::preRender(bool &skipRender, CustomScenePassModes &scenePassMode)
{
	skipRender = m_skipRender;
	W3DShaderManager::startRenderToTexture();
	return true;
}
