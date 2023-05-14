
#pragma once
#include "afxdialogex.h"


// CListBoxControl dialog

class CListBoxControl : public CDialog
{
	DECLARE_DYNAMIC(CListBoxControl)

public:
	CListBoxControl(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CListBoxControl();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CListBoxControl };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	BOOL OnInitDialog();

	void LoadListBox(CString str);

	void LoadListBox();

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedOk();
};
