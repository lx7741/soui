// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
	
CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
}

CMainDlg::~CMainDlg()
{
}

//TODO:消息映射
void CMainDlg::OnClose()
{
	SNativeWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);

	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;

	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	SWindow *pWnd = FindChildByName(L"img_soui");
	if (pWnd)
	{
		IAnimation *pAni = SApplication::getSingletonPtr()->LoadAnimation(L"anim:rotate");
		if(pAni)
		{
			pWnd->SetAnimation(pAni);
			pAni->Release();
		}
	}
	SNativeWnd::SetTimer(100,1000);	//start timer.
	return 0;
}

void CMainDlg::OnTimer(UINT_PTR idEvent)
{
	if(idEvent == 100)
	{
		SWindow *pAniHost = FindChildByName(L"wnd_ani_host");
		if (pAniHost)
		{
			const WCHAR * kLoveXml= L"<include src=\"LAYOUT:xml_love\"/>";
			SWindow *pLove = pAniHost->CreateChildren(kLoveXml);
			if(pLove)
			{
				pAniHost->UpdateLayout();
				IAnimation *pAni = SApplication::getSingletonPtr()->LoadAnimation(L"anim:test");
				if(pAni)
				{
					pAni->setStartOffset(rand()%100);//random delay max to 4000 ms to play the animation.
					pAni->setUserData((ULONG_PTR)pLove);
					pAni->setAnimationListener(this);
					pLove->SetAnimation(pAni);
					pAni->Release();
				}

			}
		}
	}else
	{
		SetMsgHandled(FALSE);
	}
}

void CMainDlg::onBtnTest()
{

}

void CMainDlg::onSouiClicked()
{
	IValueAnimator *pAni = SApplication::getSingletonPtr()->LoadValueAnimator(L"valueAni:alphaAni");
	if(pAni)
	{
		pAni->addUpdateListener(this);
		pAni->addListener(this);
		pAni->start(this);
	}
}

void CMainDlg::onAnimationStart(IValueAnimator * pAnimator)
{
	SLOG_INFO("animator start");
}

void CMainDlg::onAnimationEnd(IValueAnimator * pAnimator)
{
	SLOG_INFO("animator end");
	pAnimator->Release();
}

void CMainDlg::onAnimationRepeat(IValueAnimator * pAnimator)
{
	SLOG_INFO("animator repeat");
}

void CMainDlg::onAnimationUpdate(IValueAnimator * pAnimator)
{
	SFloatAnimator *pAni = sobj_cast<SFloatAnimator>(pAnimator);
	SWindow *pLogo = FindChildByName(L"img_soui");
	if(pLogo)
	{
		pLogo->SetAlpha((BYTE)(pAni->getValue()*255));
	}
	SLOG_INFO("animator update, value="<< pAni->getValue());
}


void CMainDlg::onAnimationStart(IAnimation * animation)
{
}

void CMainDlg::onAnimationEnd(IAnimation * animation)
{
	if(wcsicmp(animation->GetName(),L"ani_test") == 0)
	{
		SWindow *pWnd = (SWindow*)animation->getUserData();
		pWnd->DestroyWindow();
	}
}

void CMainDlg::onAnimationRepeat(IAnimation * animation)
{
}

void CMainDlg::OnToggleLeft(EventArgs *e)
{
	SToggle *pToggle = sobj_cast<SToggle>(e->sender);
	SASSERT(pToggle);
	SWindow *pWnd = FindChildByName(L"pane_left");
	if(!pWnd)
		return;
	if(pToggle->GetToggle())
	{
		IAnimation *pAni = SApplication::getSingletonPtr()->LoadAnimation(L"anim:slide_show");
		if(pAni)
		{
			pWnd->SetAnimation(pAni);
			pAni->Release();
		}
	}else
	{
		IAnimation *pAni = SApplication::getSingletonPtr()->LoadAnimation(L"anim:slide_hide");
		if(pAni)
		{
			pWnd->SetAnimation(pAni);
			pAni->Release();
		}
	}
}

