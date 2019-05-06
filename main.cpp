#include "patent.h"
#include <iomanip>

int main()
{
	Patent patent;

	/** 读取csv文件 */
	patent.ReadCSV();

	/** 处理数据，结构体写入 */
	patent.PickCSVData();

	/** 写入各自的结构体 */
	patent.PickEveStruct();
	/** 排序 */
	patent.SortForEveVector();
	/** 累加 */
	patent.TransferOfAccumulation();
	/** 计算差值 */
	patent.CalculateDifference();
	/** 计算平均值 */
	patent.CalculateAverage();
	/** 计算R值 */
	patent.CalculateRValue();
	vector<double> first_max_d = patent.GetFirestMaxDIndex();

	for (auto& max_d : first_max_d)
	{
		cout << setprecision(12) << max_d << endl;
	}

	patent.WriteCSV();

	return 0;
}