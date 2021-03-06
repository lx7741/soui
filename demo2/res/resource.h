//stamp:0aff83a14b5e0872
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				xml_love = _T("LAYOUT:xml_love");
				xml_treectrl = _T("LAYOUT:xml_treectrl");
			}
			const TCHAR * XML_MAINWND;
			const TCHAR * xml_love;
			const TCHAR * xml_treectrl;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
				png_girl = _T("IMG:png_girl");
				png_love = _T("IMG:png_love");
				png_soui = _T("IMG:png_soui");
				png_treeicon = _T("IMG:png_treeicon");
				btn_expand = _T("IMG:btn_expand");
			}
			const TCHAR * png_girl;
			const TCHAR * png_love;
			const TCHAR * png_soui;
			const TCHAR * png_treeicon;
			const TCHAR * btn_expand;
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _anim{
			public:
			_anim(){
				test = _T("anim:test");
				slide_show = _T("anim:slide_show");
				slide_hide = _T("anim:slide_hide");
				rotate = _T("anim:rotate");
			}
			const TCHAR * test;
			const TCHAR * slide_show;
			const TCHAR * slide_hide;
			const TCHAR * rotate;
		}anim;
		class _valueAni{
			public:
			_valueAni(){
				alphaAni = _T("valueAni:alphaAni");
			}
			const TCHAR * alphaAni;
		}valueAni;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_animator",65543},
		{L"btn_close",65536},
		{L"btn_max",65537},
		{L"btn_min",65539},
		{L"btn_restore",65538},
		{L"btn_test",65542},
		{L"img_soui",65541},
		{L"mytree",5000},
		{L"pane_left",65544},
		{L"tgl_left",65545},
		{L"wnd_ani_host",65540}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_animator = namedXmlID[1].strName;
			btn_close = namedXmlID[2].strName;
			btn_max = namedXmlID[3].strName;
			btn_min = namedXmlID[4].strName;
			btn_restore = namedXmlID[5].strName;
			btn_test = namedXmlID[6].strName;
			img_soui = namedXmlID[7].strName;
			mytree = namedXmlID[8].strName;
			pane_left = namedXmlID[9].strName;
			tgl_left = namedXmlID[10].strName;
			wnd_ani_host = namedXmlID[11].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_animator;
		 const wchar_t * btn_close;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_test;
		 const wchar_t * img_soui;
		 const wchar_t * mytree;
		 const wchar_t * pane_left;
		 const wchar_t * tgl_left;
		 const wchar_t * wnd_ani_host;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_animator	=	65543;
		const static int btn_close	=	65536;
		const static int btn_max	=	65537;
		const static int btn_min	=	65539;
		const static int btn_restore	=	65538;
		const static int btn_test	=	65542;
		const static int img_soui	=	65541;
		const static int mytree	=	5000;
		const static int pane_left	=	65544;
		const static int tgl_left	=	65545;
		const static int wnd_ani_host	=	65540;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
