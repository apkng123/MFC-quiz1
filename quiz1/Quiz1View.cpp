
// Quiz1View.cpp: CQuiz1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Quiz1.h"
#endif

#include "Quiz1Doc.h"
#include "Quiz1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQuiz1View

IMPLEMENT_DYNCREATE(CQuiz1View, CView)

BEGIN_MESSAGE_MAP(CQuiz1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CQuiz1View 생성/소멸

CQuiz1View::CQuiz1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CQuiz1View::~CQuiz1View()
{
}

BOOL CQuiz1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CQuiz1View 그리기

void CQuiz1View::OnDraw(CDC* pDC)
{
	CQuiz1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// CQuiz1View 인쇄

BOOL CQuiz1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CQuiz1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CQuiz1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CQuiz1View 진단

#ifdef _DEBUG
void CQuiz1View::AssertValid() const
{
	CView::AssertValid();
}

void CQuiz1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQuiz1Doc* CQuiz1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQuiz1Doc)));
	return (CQuiz1Doc*)m_pDocument;
}
#endif //_DEBUG


// CQuiz1View 메시지 처리기


int CQuiz1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(0, 100, NULL);
	m_strOutput = _T("윈도우");
	

	return 0;
}


void CQuiz1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bLRRun)
	{
		if (m_bLR)
		{
			m_ptLocation.x += 10;
		}
		else
		{
			m_ptLocation.x -= 10;
		}

		if (m_ptLocation.x >= m_ptClientSize.x)
		{
			m_bLR = false;
		}
		else if (m_ptLocation.x < 0)
		{
			m_bLR = true;
		}
	}
	if (m_bUDRun)
	{
		if (m_bUD)
		{
			m_ptLocation.y += 10;
		}
		else
		{
			m_ptLocation.y -= 10;
		}

		if (m_ptLocation.y >= m_ptClientSize.y)
		{
			m_bUD = false;
		}
		else if (m_ptLocation.y < 0)
		{
			m_bUD = true;
		}
	}
	Invalidate();


	CView::OnTimer(nIDEvent);
}


void CQuiz1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;
}


void CQuiz1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bUDRun = false;
	m_bLRRun = true;
	if (m_bLRRun)
	{
		if (m_bLR)
		{
			m_bLR = false;
		}
		else
		{
			m_bLR = true;
		}
	}
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CQuiz1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bUDRun = true;
	m_bLRRun = false;
	if (m_bUDRun)
	{
		if (m_bUD)
		{
			m_bUD = false;
		}
		else
		{
			m_bUD = true;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CQuiz1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_LEFT:
		m_bLRRun = true;
		m_bLR = false;
		m_bUDRun = false;
		break;
	case VK_RIGHT:
		m_bLRRun = true;
		m_bLR = true;
		m_bUDRun = false;
		break;
	case VK_UP:
		m_bUDRun = true;
		m_bUD = false;
		m_bLRRun = false;
		break;
	case VK_DOWN:
		m_bUDRun = true;
		m_bUD = true;
		m_bLRRun = false;
		break;
	}
	Invalidate();


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
