// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClassでウィンドウクラス名"CMainWindow"を登録.

}

// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName) {

	// メニュー名はlpctszMenuName.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName);	// CWindow::RegisterClassで, ウィンドウクラス名"CMainWindow", メニュー名lpctszMenuNameを登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() {

	// メンバの初期化.
	m_pEdit = NULL;	// m_pEditをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CMainWindow::Destroy() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// DestroyChildrenを分けたので, 自身のウィンドウ破棄は問題ない.
	// まず子ウィンドウの破棄.
	DestroyChildren();

	// 自身のウィンドウ破棄.
	bRet = CWindow::Destroy();	// 戻り値をbRetに格納.

	// bRetを返す.
	return bRet;

}

// 子ウィンドウ破棄関数DestroyChildren
BOOL CMainWindow::DestroyChildren() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// 子ウィンドウの破棄.
	if (m_pEdit != NULL) {	// NULLでなければ.
		bRet = m_pEdit->Destroy();	// m_pEdit->Destroyでウィンドウを破棄.
		delete m_pEdit;	// deleteでm_pEditを解放.
		m_pEdit = NULL;	// NULLをセット.
	}

	// 破棄したらTRUEを返す.
	if (bRet) {	// TRUEなら.
		return TRUE;	// TRUEを返す.
	}

	// 破棄しなければ, CWindowのDestroyChildrenを返す.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildrenを返す.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// エディットコアコントロールオブジェクトの作成.
	m_pEdit = new CEditCore();	// newでCEditCoreオブジェクトを作成し, ポインタをm_pEditに格納.

	// エディットコアコントロールのウィンドウ作成.
	RECT rc;	// RECT構造体rc.
	rc.left = 50;		// 左50
	rc.right = 150;		// 右150
	rc.top = 50;		// 上50
	rc.bottom = 150;	// 下150
	m_pEdit->Create(_T(""), WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでエディットコアコントロールのウィンドウ作成.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	// エディットボックスのサイズをメインウィンドウのクライアント領域に合わせる.
	if (m_pEdit != NULL) {	// NULLでない場合.
		m_pEdit->MoveWindow(0, 0, cx, cy);	// m_pEdit->MoveWindowにcx, cyを指定.
	}

	// 引数をキャプションに表示.
	TCHAR tszSize[1024] = { 0 };	// tszSize(長さ1024)を{0}で初期化.
	_stprintf(tszSize, _T("nType = %lu, cx = %d, cy = %d"), nType, cx, cy);	// _stprintfでnType, cx, cyをテキストtszSizeに変換.
	SetWindowText(tszSize);	// SetWindowTextでtszSizeをキャプションにセット.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("BFCSample15"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}