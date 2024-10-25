
// Quiz1View.h: CQuiz1View 클래스의 인터페이스
//

#pragma once


class CQuiz1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CQuiz1View() noexcept;
	DECLARE_DYNCREATE(CQuiz1View)

// 특성입니다.
public:
	CQuiz1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CQuiz1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutput;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CPoint m_ptLocation = (0,0);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CPoint m_ptClientSize;
	bool m_bLR = true;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	bool m_bUD;
	bool m_bUDRun = false;
	bool m_bLRRun = true;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Quiz1View.cpp의 디버그 버전
inline CQuiz1Doc* CQuiz1View::GetDocument() const
   { return reinterpret_cast<CQuiz1Doc*>(m_pDocument); }
#endif

