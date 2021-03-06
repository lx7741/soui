// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <valueAnimator\ValueAnimator.h>

class CMainDlg : public SHostWnd, IAnimation::IAnimationListener, IValueAnimator::IAnimatorListener, IValueAnimator::IAnimatorUpdateListener
{
public:
	CMainDlg();
	~CMainDlg();


protected:
	//IAnimation::IAnimationListener
	virtual void onAnimationStart(IAnimation * animation);

	virtual void onAnimationEnd(IAnimation * animation);

	virtual void onAnimationRepeat(IAnimation * animation);

	// 通过 IAnimatorListener 继承
	virtual void onAnimationStart(IValueAnimator * pAnimator) override;
	virtual void onAnimationEnd(IValueAnimator * pAnimator) override;
	virtual void onAnimationRepeat(IValueAnimator * pAnimator) override;

	// 通过 IAnimatorUpdateListener 继承
	virtual void onAnimationUpdate(IValueAnimator * pAnimator) override;

protected:
	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();

	void onBtnTest();
	void onSouiClicked();
	void OnToggleLeft(EventArgs *e);
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_test",onBtnTest)
		EVENT_NAME_COMMAND(L"img_soui",onSouiClicked)
		EVENT_NAME_HANDLER(L"tgl_left",EventCmd::EventID,OnToggleLeft)
	EVENT_MAP_END()
		
protected:
	void OnSize(UINT nType, CSize size);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	void OnTimer(UINT_PTR idEvent);

	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_TIMER(OnTimer)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

};
