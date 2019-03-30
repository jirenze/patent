#pragma once
#include <string>

using namespace std;

struct  Patent_Data_S
{
	/** 文献号 */
	string literature;

	/** 是否转让 */
	int transfer;

	/** 说明书页数 */
	double instruction_num;

	/** 附图个数 */
	double image_num;

	/** 文献引证数 */
	double non_patent_citation_num;

	/** 专利引证数 */
	double citation_num;

	/** 引证本国专利数*/
	double citation_of_domestic_num;

	/** 引证外国专利数 */
	double citation_of_foreign_num;

	/** 专利类别 */
	float patent_type;

	/** 保护期 */
	float term_of_patent_protection;

	/** 分类数 */
	double classify_num;

	/** IPC大类数 */
	double IPC_large_classify_num;

	/** IPC小类数 */
	double IPC_sub_classify_num;

	/** 同族专利数 */
	double kin_num;

	/** 同族布局国家、地区数 */
	double kin_of_country_num;

	/** 是否为PCT申请 */
	int PCT_apply;

	/** 是否为五国专利/四方专利 */
	int five_four_countries_patent;

	/** 专利国别代码 */
	int country_code;

	/** 申请日公开日时间间隔（年）*/
	double application_open_day_interval;

	/** 申请日授权日时间间隔 */
	double application_authorization_day_interval;

	/** 公开日授权日时间间隔 */
	double open_authorization_day_interval;

	/** 剩余有效期 */
	float survival_time;

	/** 是否有优先权 */
	int prority;

	/** 权项数 */
	double right_num;

	/** 发明人数 */
	double num_of_invention;

	/** 申请人数 */
	float num_of_application;

	/** 专利权人数 */
	float current_num_of_patent;

	/** 申请人类型 */
	float type_of_application;
};

/** 顺序参照 */
enum Enum_Patent
{
	/** 文献号 */
	E_literature,

	/** 是否转让 */
	E_transfer,

	/** 说明书页数 */
	E_instruction_num,

	/** 附图个数 */
	E_image_num,

	/** 文献引证数 */
	E_non_patent_citation_num,

	/** 专利引证数 */
	E_citation_num,

	/** 引证本国专利数*/
	E_citation_of_domestic_num,

	/** 引证外国专利数 */
	E_citation_of_foreign_num,

	/** 专利类别 */
	E_patent_type,

	/** 保护期 */
	E_term_of_patent_protection,

	/** 分类数 */
	E_classify_num,

	/** IPC大类数 */
	E_IPC_large_classify_num,

	/** IPC小类数 */
	E_IPC_sub_classify_num,

	/** 同族专利数 */
	E_kin_num,

	/** 同族布局国家、地区数 */
	E_kin_of_country_num,

	/** 是否为PCT申请 */
	E_PCT_apply,

	/** 是否为五国专利/四方专利 */
	E_five_four_countries_patent,

	/** 专利国别代码 */
	E_country_code,

	/** 申请日公开日时间间隔（年）*/
	E_application_open_day_interval,

	/** 申请日授权日时间间隔 */
	E_application_authorization_day_interval,

	/** 公开日授权日时间间隔 */
	E_open_authorization_day_interval,

	/** 剩余有效期 */
	E_survival_time,

	/** 是否有优先权 */
	E_prority,

	/** 权项数 */
	E_right_num,

	/** 发明人数 */
	E_num_of_invention,

	/** 申请人数 */
	E_num_of_application,

	/** 专利权人规模 */
	E_current_num_of_patent,

	/** 申请人类型 */
	E_type_of_application,
};


struct Base_Struct
{
	/** 文献号 */
	string literature;

	/** 是否转让 */
	bool transfer;
};

struct Instruction_Num : Base_Struct
{
	/** 说明书页数 */
	double instruction_num;
};

struct Image_Num : Base_Struct
{
	/** 附图个数 */
	double image_num;
};

struct Non_Patent_Citation_Num : Base_Struct
{
	/** 文献引证数 */
	double non_patent_citation_num;
};

struct Citation_Num : Base_Struct
{
	/** 专利引证数 */
	double citation_num;
};

struct Citation_Of_Domestic_Num : Base_Struct
{
	/** 引证本国专利数*/
	double citation_of_domestic_num;
};

struct Citation_Of_Foreign_Num : Base_Struct
{
	/** 引证外国专利数 */
	double citation_of_foreign_num;
};

struct Patent_Type : Base_Struct
{
	/** 专利类别 */
	float patent_type;
};

struct Term_Of_Patent_Protection : Base_Struct
{
	/** 保护期 */
	float term_of_patent_protection;
};

struct Classify_Num : Base_Struct
{
	/** 分类数 */
	double classify_num;
};

struct IPC_Large_Classify_Num : Base_Struct
{
	/** IPC大类数 */
	double IPC_large_classify_num;
};

struct IPC_Sub_Classify_Num : Base_Struct
{
	/** IPC小类数 */
	double IPC_sub_classify_num;
};

struct Kin_Num : Base_Struct
{
	/** 同族专利数 */
	double kin_num;
};

struct Kin_Of_Country_Num : Base_Struct
{
	/** 同族布局国家、地区数 */
	double kin_of_country_num;
};

struct PCT_Apply : Base_Struct
{
	/** 是否为PCT申请 */
	int PCT_apply;
};

struct Five_Four_Countries_Patent : Base_Struct
{
	/** 是否为五国专利/四方专利 */
	int five_four_countries_patent;
};

struct Country_code :Base_Struct
{
	/** 专利国别代码 */
	int country_code;
};

struct Application_Open_Day_Interval : Base_Struct
{
	/** 申请日公开日时间间隔（年）*/
	double application_open_day_interval;
};

struct Application_Authorization_Day_Interval : Base_Struct
{
	/** 申请日授权日时间间隔 */
	double application_authorization_day_interval;
};

struct Open_Authorization_Day_Interval : Base_Struct
{
	/** 公开日授权日时间间隔 */
	double open_authorization_day_interval;
};

struct Survival_Time : Base_Struct
{
	/** 剩余有效期 */
	float survival_time;
};

struct PRORITY : Base_Struct
{
	/** 是否有优先权 */
	int prority;
};

struct Right_Num : Base_Struct
{
	/** 权项数 */
	double right_num;
};

struct Num_Of_Invention : Base_Struct
{
	/** 发明人数 */
	double num_of_invention;
};

struct Num_Of_Application : Base_Struct
{
	/** 申请人数 */
	float num_of_application;
};

struct Current_Num_Of_Patent : Base_Struct
{
	/** 专利权人数 */
	float current_num_of_patent;
};

struct Type_Of_Application : Base_Struct
{
	/** 申请人类型 */
	float type_of_application;
};

struct Transfer_Data
{
	/** 转让累加数 */
	vector<double> transfer_add_index;

	/** 未转让累加数 */
	vector<double> untransfer_add_index;

	/** 转让数 */
	double untransfer_num;

	/** 未转让数 */
	double transfer_num;

	/** D最大值 */
	double first_max_d;
};
