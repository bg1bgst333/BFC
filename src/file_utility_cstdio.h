/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */
#include <string.h>	/* 文字列処理 */
#include <sys/stat.h>	/* ファイル状態 */

/* 関数のプロトタイプ宣言 */
int print_file_text_cstdio(const char* path, const char* text);	/* 関数print_file_text_cstdioの宣言 */
size_t get_file_size(const char* path);	/* 関数get_file_sizeの宣言. */
int scan_file_text_cstdio(const char* path, char* text);	/* 関数scan_file_text_cstdioの宣言. */
int put_file_text_cstdio(const char* path, const char* text);	/* 関数put_file_text_cstdioの宣言. */
char* get_file_text_cstdio(const char* path, char* text, size_t buf_size);	/* 関数get_file_text_cstdioの宣言. */
int write_file_text_cstdio(const char* path, const char* text, size_t len);	/* 関数write_file_text_cstdioの宣言. */
size_t read_file_text_cstdio(const char* path, char* text, size_t len);	/* 関数read_file_text_cstdioの宣言. */
int write_file_binary_cstdio(const char* path, const void* bytes, size_t size);	/* 関数write_file_binary_cstdioの宣言. */
size_t read_file_binary_cstdio(const char* path, void* bytes, size_t size);	/* 関数read_file_binary_cstdioの宣言. */
int write_file_binary_cstdio_w(const wchar_t* path, const void* bytes, size_t size);	/* 関数write_file_binary_cstdio_wの宣言. */
size_t read_file_binary_cstdio_w(const wchar_t* path, void* bytes, size_t size);	/* 関数read_file_binary_cstdio_wの宣言. */
size_t get_file_size_w(const wchar_t* path);	/* 関数get_file_size_wの宣言. */
/* この場合, こういった書き方じゃないとコンパイルエラーになる模様. */
#ifdef __cplusplus
extern "C" {
#endif
	void swap_2bytes(char* byte1, char* byte2);	/* 関数swap_2bytesの宣言. */
	int convert_endian_16bit_byte_array(const char* src, char* dest, size_t len);	/* 関数convert_endian_16bit_byte_arrayの宣言. */
#ifdef __cplusplus
}
#endif
#endif