
// MFCApplicationListboxView.cpp : implementation of the CMFCApplicationListboxView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplicationListbox.h"
#endif

#include "MFCApplicationListboxDoc.h"
#include "MFCApplicationListboxView.h"

#include "CListBoxControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationListboxView

IMPLEMENT_DYNCREATE(CMFCApplicationListboxView, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationListboxView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplicationListboxView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_NEW, &CMFCApplicationListboxView::OnFileNew)
END_MESSAGE_MAP()

// CMFCApplicationListboxView construction/destruction

CMFCApplicationListboxView::CMFCApplicationListboxView() noexcept
{
	// TODO: add construction code here

}

CMFCApplicationListboxView::~CMFCApplicationListboxView()
{
}

BOOL CMFCApplicationListboxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationListboxView drawing

void CMFCApplicationListboxView::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationListboxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApplicationListboxView printing


void CMFCApplicationListboxView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplicationListboxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationListboxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplicationListboxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplicationListboxView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationListboxView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplicationListboxView diagnostics

#ifdef _DEBUG
void CMFCApplicationListboxView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationListboxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationListboxDoc* CMFCApplicationListboxView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationListboxDoc)));
	return (CMFCApplicationListboxDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationListboxView message handlers


void CMFCApplicationListboxView::OnFileNew()
{
	// TODO: Add your command handler code here
	CListBoxControl CListBox;
	CListBox.DoModal();

}



