#include "patent.h"
#include <iomanip>

int main()
{
	Patent patent;

	/** ��ȡcsv�ļ� */
	patent.ReadCSV();

	/** �������ݣ��ṹ��д�� */
	patent.PickCSVData();

	/** д����ԵĽṹ�� */
	patent.PickEveStruct();

	/** ���� */
	patent.SortForEveVector();

	/** �ۼ� */
	patent.TransferOfAccumulation();
	
	/** ���ݽṹ�� */
	patent.AddTransferStruct();

	/** �����ֵ */
	patent.CalculateDifference();

	vector<double> first_max_d = patent.GetFirestMaxDIndex();

	for (auto& max_d : first_max_d)
	{
		cout << setprecision(12) << max_d << endl;
	}

	patent.WriteCSV();

	return 0;
}