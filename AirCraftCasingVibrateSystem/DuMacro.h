
#pragma once

#include <vector>
#include <list>
#include <map>
using namespace std;

typedef std::vector<int>					    STD_VECTOR_INT;
typedef std::vector<float>					    STD_VECTOR_FLOAT;
typedef std::vector<unsigned char>              STD_VECTOR_UCHAR;
typedef std::map<int, std::string>              STD_MAP_INT_STRING;
typedef std::map<int, float>                    STD_MAP_INT_FLOAT;
typedef std::map<int, long long>                STD_MAP_INT_LONGLONG;
typedef std::multimap<int, int>                 STD_MULTIMAP_INT_INT;
typedef STD_VECTOR_UCHAR::iterator              STD_VECTOR_UCHAR_ITR;
typedef STD_VECTOR_FLOAT::iterator              STD_VECTOR_FLOAT_ITR;
typedef STD_MAP_INT_STRING::iterator            STD_MAP_INT_STRING_ITR;
typedef STD_MAP_INT_FLOAT::iterator             STD_MAP_INT_FLOAT_ITR;
typedef STD_MAP_INT_LONGLONG::iterator          STD_MAP_INT_LONGLONG_ITR;

typedef std::vector<int>						VECTORINT;
typedef VECTORINT::iterator						VECTORINTITR;
typedef std::vector<UINT>						VECTORUINT;
typedef VECTORUINT::iterator					VECTORUINTITR;
typedef std::vector<CString>					VECTORSTRING;
typedef VECTORSTRING::iterator					VECTORSTRINGITR;
typedef std::vector<unsigned char>				VECTORUCHAR;
typedef VECTORUCHAR::iterator					VECTORUCHARITR;
typedef std::vector<float>						VECTORFLOAT;
typedef VECTORFLOAT::iterator					VECTORFLOATITR;
typedef std::vector<double>						VECTORDOUBLE;
typedef VECTORDOUBLE::iterator					VECTORDOUBLEITR;
typedef std::vector<std::string>				VECTORSTDSTRING;
typedef VECTORSTDSTRING::iterator				VECTORSTDSTRINGITR;
typedef std::vector<std::wstring>				VECTORSTDWSTRING;
typedef VECTORSTDWSTRING::iterator				VECTORSTDWSTRINGITR;

typedef std::vector<VECTORSTRING>				VECTORVECTORSTRING;
typedef std::vector<VECTORINT>					VECTORVECTORINT;
typedef std::vector<CView*>						VECTORCVIEWPTR;
typedef std::vector<CRect>						VECTORCRECT;

typedef std::list<int>							LISTITN;
typedef LISTITN::iterator						LISTITNITE;
typedef std::list<DWORD_PTR>					LISTPTR;
typedef LISTPTR::iterator						LISTPTRITR;

typedef std::map<int, CString>					MAPINTSTRING;
typedef MAPINTSTRING::iterator					MAPINTSTRINGITR;
typedef std::map<int, int>						MAPINTINT;
typedef MAPINTINT::iterator						MAPINTINTITR;
typedef std::map<int, float>					MAPINTFLOAT;
typedef MAPINTFLOAT::iterator					MAPINTFLOATITR;
typedef std::map<DWORD, int>					MAPDWORDINT;
typedef MAPDWORDINT::iterator					MAPDWORDINTITR;
typedef std::map<CString, unsigned char>		MAPSTRINGUCHAR;
typedef MAPSTRINGUCHAR::iterator				MAPSTRINGUCHARITR;
typedef std::map<unsigned char, unsigned char>  MAPUCHARUCHAR;
typedef MAPUCHARUCHAR::iterator                 MAPUCHARUCHARITR;

typedef std::multimap<int, int>					MULMAPINTINT;
typedef MULMAPINTINT::iterator					MULMAPINTINTITR;

#define DU_MACRO_NEW_BASIC_ARRAY(p, T, n) p = new T[(n)]; memset(p, 0, sizeof(T) * (n));

#define DU_MACRO_ARRAY_ELEMENT_COUNT(ary) (sizeof(ary) / sizeof(ary[0]))

#define DU_MACRO_SAFE_DELETE_PTR(p)         if (NULL != (p)) {delete (p); (p) = NULL;}
#define DU_MACRO_SAFE_DELETE_PTR_ARRAY(p)   if (NULL != (p)) {delete[] (p); (p) = NULL;}
#define DU_MACRO_SAFE_DELETE_OBJECT(h)      if (NULL != (h)) {::DeleteObject(h);}
#define DU_MACRO_SAFE_CLOSE_HANDLE(h)       if (NULL != (h)) {::CloseHandle(h);}
#define DU_MACRO_SAFE_DESTROY_WND_PTR(p)    if (NULL != (p)) {if (NULL != (p)->m_hWnd) (p)->DestroyWindow();}

#define DU_MACRO_ASSERT_FALSE_RETURN_FALSE(p)		if (!(p)) {ASSERT(FALSE); return FALSE;}
#define DU_MACRO_ASSERT_FALSE_RETURN(p)				if (!(p)) {ASSERT(FALSE); return;}
#define DU_MACRO_ASSERT_NULL_RETURN_FALSE(p)		if (NULL == (p)) {ASSERT(FALSE); return FALSE;}
#define DU_MACRO_ASSERT_NULL_RETURN_NULL(p)			if (NULL == (p)) {ASSERT(FALSE); return NULL;}
#define DU_MACRO_ASSERT_NULL_CONTINUE(p)			if (NULL == (p)) {ASSERT(FALSE); continue;}
#define DU_MACRO_ASSERT_NULL_BREAK(p)				if (NULL == (p)) {ASSERT(FALSE); break;}
#define DU_MACRO_ASSERT_NULL_RETURN(p)				if (NULL == (p)) {ASSERT(FALSE); return;}
#define DU_MACRO_ASSERT_NULL_RETURN_EMPTYSTRING(p)	if (NULL == (p)) {ASSERT(FALSE); return TEXT("");}

#define DU_MACRO_GET(T, N, V) \
public : \
	T Get##V() const {return  m_##N##V;}

#define DU_MACRO_SET_GET(T, N, V) \
public : \
    T Get##V() const {return  m_##N##V;} \
    void Set##V(const T t) {m_##N##V = (t);}

#define DU_MACRO_GET_OBJECT_POINTER(T, N, V) \
public: \
    T * Get##V##Ptr() {return &m_##N##V;}

#define DU_MACRO_GET_POINTER(T, M) \
public : \
	T * Get##M() const {return m_p##M;}

#define DU_MACRO_SET_GET_POINTER(T, M) \
public : \
    T * Get##M() const {return m_p##M;} \
    void Set##M(T * m) {m_p##M = m;}

#define DU_MACRO_SET_GET_STRING(M) \
public : \
    LPCTSTR Get##M() const {return m_str##M;} \
    void Set##M(LPCTSTR m) {m_str##M = m;}

#define DU_STRING_POP_WHETHER_COVER_PROJECT							TEXT("工程 %s\n已经存在，覆盖会造成数据丢失，是否确认覆盖？")
#define DU_STRING_POP_MAX_LINE_COUNT								TEXT("视图窗口最多支持 %d 个通道，请新建视图窗口！")
#define DU_STRING_POP_THIS_VIEWWND_ONLY_SUPPORT_THIS_INS_CHANNEL	TEXT("该视图窗口只支持该仪器的通道，请新建视图窗口！")
#define DU_STRING_POP_CHANNEL_TYPE_NOT_SAME							TEXT("通道信号类型不一致，请新建视图窗口！")
#define DU_STRING_MESSAGEBOX_TITLE_ERROR							TEXT("错误")
#define DU_STRING_SAVE_SUCCESS_WHETHER_OPEN                         "已经成功保存，是否现在打开文件查看？"
