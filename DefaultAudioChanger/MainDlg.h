// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CDevicesManager;

class CMainDlg : public CDialogImpl<CMainDlg>, public CUpdateUI<CMainDlg>,
		public CMessageFilter, public CIdleHandler
{
public:
	enum { IDD = IDD_MAINDLG };
    enum
    {
        WM_FIRST = WM_APP,
        WM_SYSTEMTRAYICON,
    };

	CMainDlg();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainDlg)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainDlg)				
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDCLOSE, OnBtnClose)		
		MSG_WM_SYSCOMMAND(OnSysCommand)
		MESSAGE_HANDLER_EX(WM_SYSTEMTRAYICON, OnSystemTrayIcon)
		COMMAND_ID_HANDLER_EX(ID_POPUPMENU_OPTIONS, OnScRestore)
		COMMAND_ID_HANDLER_EX(ID_POPUPMENU_EXIT, OnScClose)
		COMMAND_HANDLER(IDC_HIDE_BUTTON, BN_CLICKED, OnBnClickedHideButton)		
		MSG_WM_CTLCOLORDLG(OnCtlColorDlg)
		MSG_WM_CTLCOLORSTATIC(OnCtlColorStatic)
		COMMAND_HANDLER(IDC_SWITCH_BUTTON, BN_CLICKED, OnBnClickedSwitchButton)
		COMMAND_ID_HANDLER(ID_POPUPMENU_SWITCH,OnBnClickedSwitchButton)
		NOTIFY_HANDLER(IDC_DEVICES_LIST,LVN_ITEMCHANGED,OnItemChanged)
		COMMAND_RANGE_HANDLER(WM_USER+1,WM_USER+100,OnSpecificDeviceSelected)/*This means we can only have 100 devices*/
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
	
	LRESULT OnSpecificDeviceSelected(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnItemChanged(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/);	
	HBRUSH OnCtlColorStatic(CDCHandle dc, CStatic wndStatic);
	HBRUSH OnCtlColorDlg(CDCHandle dc, CWindow wnd);
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBtnClose(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);	
	LRESULT OnSysCommand(UINT nCommand, CPoint point);
	LRESULT OnSystemTrayIcon(UINT, WPARAM wParam, LPARAM lParam);
	LRESULT OnScClose(UINT, INT, HWND);
	LRESULT OnScRestore(UINT, INT, HWND);
	LRESULT OnBnClickedHideButton(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	void CloseDialog(int nVal);
	BOOL ShowTrayIcon();
	void SetDevicesManager(CDevicesManager* devicesManager);
	LRESULT OnBnClickedSwitchButton(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	void SetDeviceSettingsKey(HKEY key);
	void UpdateApplicationIcon();
private:
	NOTIFYICONDATA notifyIconData;
	CDevicesManager* devicesManager;
	CListViewCtrl  listView;
	CMenu popupMenu;
	HBRUSH m_hDialogBrush;
	HKEY deviceSettingsKey;
public:
	
};