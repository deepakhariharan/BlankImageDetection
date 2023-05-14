#include "stdafx.h"
// CListBoxControl.cpp : implementation file
//


#include "pch.h"
#include "MFCApplicationListbox.h"
#include "afxdialogex.h"
#include "CListBoxControl.h"
#include <iostream>

//#include <core/core.hpp>

//#include <highgui/highgui.hpp>

//#include <opencv.hpp>

using namespace std;
//using namespace cv;



#include <windows.h>
#include <string>
#include <vector>
#include <stack>
#include <iostream>



// CListBoxControl dialog

IMPLEMENT_DYNAMIC(CListBoxControl, CDialog)

CListBoxControl::CListBoxControl(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CListBoxControl, pParent)
{

}

CListBoxControl::~CListBoxControl()
{
}

void CListBoxControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
}


BEGIN_MESSAGE_MAP(CListBoxControl, CDialog)
	ON_BN_CLICKED(IDC_BUTTON, &CListBoxControl::OnBnClickedButton)
	ON_BN_CLICKED(IDOK, &CListBoxControl::OnBnClickedOk)
END_MESSAGE_MAP()


// CListBoxControl message handlers
BOOL CListBoxControl::OnInitDialog() {
	CDialog::OnInitDialog();

	
	// TODO: Add extra initialization here
	//LoadListBox();
	
	return TRUE; // return TRUE unless you set the focus to a control
}

void CListBoxControl::LoadListBox(CString str ) {
	

		
		m_listbox.AddString(str);
	
}

bool ListFiles(wstring path, wstring mask, vector<wstring>& files);

void CListBoxControl::OnBnClickedButton()
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox(_T("Cllicked Read Files"));

	CDC* pDC;
	pDC = NULL;

	CString str = _T("");

	vector<wstring> files;

	AfxMessageBox(_T("Please create a Folder C:\\Test and Load all the Images in that Folder"));

	if (ListFiles(L"C:\\Test", L"*", files)) {
		
		for (vector<wstring>::iterator it = files.begin();
			it != files.end();
			++it) {
			//wcout << it->c_str() << endl;
			//AfxMessageBox(_T("Cllicked Read Files by User"));
			//str = _T("Deepak Hariharan");
			str = it->c_str();
			LoadListBox(str);




		}
	}

	


}



bool ListFiles(wstring path, wstring mask, vector<wstring>& files) {

	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA ffd;
	wstring spec;
	stack<wstring> directories;
	directories.push(path);
	files.clear();


	while (!directories.empty()) {
		path = directories.top();
		spec = path + L"\\" + mask;
		directories.pop();

		hFind = FindFirstFile(spec.c_str(), &ffd);
		if (hFind == INVALID_HANDLE_VALUE) {
			return false;
		}

		do {
			if (wcscmp(ffd.cFileName, L".") != 0 &&
				wcscmp(ffd.cFileName, L"..") != 0) {
				if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
					directories.push(path + L"\\" + ffd.cFileName);
				}
				else {
					files.push_back(path + L"\\" + ffd.cFileName);
				}
			}
		} while (FindNextFile(hFind, &ffd) != 0);

		if (GetLastError() != ERROR_NO_MORE_FILES) {
			FindClose(hFind);
			return false;
		}

		FindClose(hFind);
		hFind = INVALID_HANDLE_VALUE;
	}






	return true;
}


void CListBoxControl::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	/*Mat image = imread("C:/Test/Image-1.jpg");
	Vec3b buf;
	int array_B[50][50];
	int array_G[50][50];
	int array_R[50][50];
	for (int i = 0; i < image.rows; i++)
		for (int j = 0; j < image.cols; j++)
		{
			buf = image.at<Vec3b>(i, j);
			array_B[i][j] = buf[0];
			array_G[i][j] = buf[1];
			array_R[i][j] = buf[2];
		}

	//imwrite("C:/.../image2.jpg",image3);
	imshow("Image", image);
	waitKey(0);*/


	CDialog::OnOK();



	AfxMessageBox(_T("Cllicked Read Files by User"));





}
