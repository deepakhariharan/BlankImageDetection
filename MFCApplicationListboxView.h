
// MFCApplicationListboxView.h : interface of the CMFCApplicationListboxView class
//

#pragma once


class CMFCApplicationListboxView : public CView
{
protected: // create from serialization only
	CMFCApplicationListboxView() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationListboxView)

// Attributes
public:
	CMFCApplicationListboxDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApplicationListboxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // debug version in MFCApplicationListboxView.cpp
inline CMFCApplicationListboxDoc* CMFCApplicationListboxView::GetDocument() const
   { return reinterpret_cast<CMFCApplicationListboxDoc*>(m_pDocument); }
#endif

