//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int Width = 10;
//int Heigth = 11;
//
//char HorizontalBoard[] = "% A B C D E F G H I J";
//char DotArray[] =			 " . . . . . . . . . .";
//char VertBoard[] = "0123456789";
//
//
//void Print(char arrayChar[], int length, bool isNewLine = false, bool isNewLineEnd = false, char arrayChar2[] = NULL, int length2 = 0)
//{
//	for (int i = 0, j = 0; i < length; i++)	
//	{
//		
//			cout << arrayChar[i];		
//
//			if (isNewLine)
//			{
//				if (arrayChar2 != NULL)
//				{
//
//					for (int i = 0; i < length2; i++)
//					{
//
//						cout << arrayChar2[i];
//
//					}
//				}
//				cout << endl;
//			}			
//		
//	}
//
//	cout << endl;
//
//	if (isNewLineEnd)
//	{
//		cout << endl;
//	}
//}
//void PrintBorderDot()
//{
//	int width = sizeof(DotArray);
//	int heigth = sizeof(VertBoard);
//	
//}
//void PrintBorderHorizontal()
//{
//	int width =  sizeof(HorizontalBoard) - 1;
//	Print(HorizontalBoard, width,false);
//}
//void PrintBorderVertical()
//{
//	int heigth = sizeof(VertBoard) - 1;
//	int width = sizeof(DotArray) - 1;
//
//	//Print(VertBoard, heigth, true);
//	Print(VertBoard, heigth, true, false, DotArray, width);
//}
//void PrintBoarders()
//{
//	PrintBorderHorizontal();
//	PrintBorderVertical();
//}
//
//
//
