/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int print_file_text_cstdio(const char* path, const char* text) {

	/* 変数・構造体・ポインタの初期化 */
	FILE* fp = NULL;	/* ファイルポインタをNULLで初期化. */
	int ret = 0;	/* 書き込んだバイト数retを0で初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fprintf(fp, "%s", text);	/* fprintfでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* 書き込んだバイト数retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* ファイルサイズの取得. */
size_t get_file_size(const char* path) {

	/* 構造体の初期化. */
	struct _stat sst = { 0 };	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_stat(path, &sst);	/* _statでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル入力. */
int scan_file_text_cstdio(const char* path, char* text) {

	/* 変数・構造体の初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret = 0;	/* 格納した変数の数retを0に初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "r");	/* fopenでテキスト読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからテキストを読み込む. */
		ret = fscanf(fp, "%s", text);	/* fscanfでfpから入力しtextに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* 格納した変数の数retを返す. */
		return ret; /* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int put_file_text_cstdio(const char* path, const char* text) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fputsの戻り値ret. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fputs(text, fp);	/* fputsでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* fputsが成功ならretは0. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル入力. */
char* get_file_text_cstdio(const char* path, char* text, size_t buf_size) {

	/* 構造体・ポインタの宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	char* ret;	/* 格納した文字列ポインタret. */

	/* ファイルを開く. */
	fp = fopen(path, "r");	/* fopenでテキスト読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからテキストを読み込む. */
		ret = fgets(text, buf_size, fp);	/* fgetsでfpから入力しtextに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, NULLを返す. */
	return NULL;	/* returnでNULLを返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int write_file_text_cstdio(const char* path, const char* text, size_t len) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fwriteの戻り値ret. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fwrite(text, sizeof(char), len, fp);	/* fwriteでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル入力. */
size_t read_file_text_cstdio(const char* path, char* text, size_t len) {

	/* 構造体・ポインタの宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだ文字数ret. */

	/* ファイルを開く. */
	fp = fopen(path, "r");	/* fopenでテキスト読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからテキストを読み込む. */
		ret = fread(text, sizeof(char), len, fp);	/* freadでfpから入力しtextに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}

/* C標準入出力ライブラリ関数でバイナリファイル出力. */
int write_file_binary_cstdio(const char* path, const void* bytes, size_t size) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fwriteの戻り値ret. */

	/* ファイルを開く. */
	fp = fopen(path, "wb");	/* fopenでバイナリ書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにバイナリを書き込む. */
		ret = fwrite(bytes, sizeof(char), size, fp);	/* fwriteでfpにbytesを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* C標準入出力ライブラリ関数でバイナリファイル入力. */
size_t read_file_binary_cstdio(const char* path, void* bytes, size_t size) {

	/* 構造体・ポインタの宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだ文字数ret. */

	/* ファイルを開く. */
	fp = fopen(path, "rb");	/* fopenでバイナリ読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからバイナリを読み込む. */
		ret = fread(bytes, sizeof(char), size, fp);	/* freadでfpから入力しbytesに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}

/* C標準入出力ライブラリ関数でバイナリファイル出力. */
int write_file_binary_cstdio_w(const wchar_t* path, const void* bytes, size_t size) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fwriteの戻り値ret. */

	/* ファイルを開く. */
	fp = _wfopen(path, L"wb");	/* _wfopenでバイナリ書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにバイナリを書き込む. */
		ret = fwrite(bytes, sizeof(char), size, fp);	/* fwriteでfpにbytesを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* C標準入出力ライブラリ関数でバイナリファイル入力. */
size_t read_file_binary_cstdio_w(const wchar_t* path, void* bytes, size_t size) {

	/* 構造体・ポインタの宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだ文字数ret. */

	/* ファイルを開く. */
	fp = _wfopen(path, L"rb");	/* _wfopenでバイナリ読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからバイナリを読み込む. */
		ret = fread(bytes, sizeof(char), size, fp);	/* freadでfpから入力しbytesに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}

/* ファイルサイズの取得. */
size_t get_file_size_w(const wchar_t* path) {

	/* 構造体の初期化. */
	struct _stat sst = { 0 };	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_wstat(path, &sst);	/* _wstatでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* 2つのバイト値を入れ替える. */
void swap_2bytes(char* byte1, char* byte2) {

	/* 変数の宣言 */
	char temp;	/* char型一時変数temp. */

	/* byte1の指す値とbyte2の指す値を入れ替える. */
	temp = *byte1;	/* byte1の指す値をtempに代入. */
	*byte1 = *byte2;	/* byte2の指す値をbyte1に代入. */
	*byte2 = temp;	/* tempの値をbyte2の指す値に代入. */

}

/* バイト列のエンディアン変換(bigならlittle, littleならbig.) */
int convert_endian_16bit_byte_array(const char* src, char* dest, size_t len) {

	/* 変数の初期化 */
	int half = 0;	/* 長さの半分harfを0で初期化. */
	int i = 0;	/* ループ用変数iを0で初期化. */
	int a, b;	/* 入れ替え用一時変数a, b. */

	/* 長さが奇数の場合はエラー. */
	if (len % 2) {	/* 奇数. */
		return -1;	/* -1を返す. */
	}

	/* エンディアン変換 */
	half = len / 2;	/* lenの半分の長さをhalfに代入. */
	for (i = 0; i < half; i++) {	/* halfの前まで繰り返す. */
		*(dest + 2 * i) = *(src + 2 * i);
		*(dest + 2 * i + 1) = *(src + 2 * i + 1);
		swap_2bytes(dest + 2 * i, dest + 2 * i + 1);
	}

	/* 正常終了 */
	return 0;	/* 0を返す. */

}