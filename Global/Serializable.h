//CodeTranslator.h
#ifndef _CODETRANSLATOR_H_
#define _CODETRANSLATOR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//字符串编码:定义ret为编码字符串
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PACK_INT(X)               {ret.append((char*)(&X), sizeof(int));}
#define PACK_INT64(X)             {ret.append((char*)(&X), sizeof(__int64));}
#define PACK_SHORT(X)             {ret.append((char*)(&X), sizeof(short));}
#define PACK_LONG(X)              {ret.append((char*)(&X), sizeof(long));}
#define PACK_CHAR(X)              {ret.append((char*)(&X), sizeof(char));}
#define PACK_UINT                 PACK_INT
#define PACK_USHORT               PACK_SHORT
#define PACK_ULONG                PACK_LONG
#define PACK_UCHAR                PACK_CHAR
#define PACK_STRING(X)            {int str_size=X.size();PACK_UINT(str_size);ret.append(X.c_str(), X.size());}
#define PACK_STRING_RAW(X)        {ret.append(X.c_str(), X.size());}
#define PACK_DOUBLE(X)            {ret.append((char*)(&X), sizeof(double));}
#define PACK_FLOAT(X)             {ret.append((char*)(&X), sizeof(float));}
#define PACK_CLASS(X)             {ret.append(X.toString());}
#define PACK_CLASS_ARRAY(X, N)    {size_t array_size=N;PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_CLASS(X[i]);}}
#define PACK_STRING_ARRAY(X, N)   {size_t array_size=N;PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_STRING(X[i]);}}
#define PACK_DOUBLE_ARRAY(X, N)   {size_t array_size=N;PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_DOUBLE(X[i]);}}
#define PACK_ULONG_VECTOR(X)      {size_t array_size=X.size();PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_ULONG(X.at(i));}}
#define PACK_UINT_VECTOR(X)       {size_t array_size=X.size();PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_UINT(X.at(i));}}
#define PACK_UCHAR_VECTOR(X)      {size_t array_size=X.size();PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_UCHAR(X.at(i));}}
#define PACK_CLASS_VECTOR(X)      {size_t array_size=X.size();PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_CLASS(X.at(i));}}
#define PACK_UINT_ARRAY(X, N)     {size_t array_size=N;PACK_UINT(array_size);for(int i=0;i<array_size;i++){PACK_UINT(X[i]);}}
#define PACK_USHORT_ARRAY(X, N)   {size_t array_size=N;PACK_USHORT(array_size);for(int i=0;i<array_size;i++){PACK_USHORT(X[i]);}}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//字符串解码:定义pstr为解码字符串
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#define UNPACK_INT(X)             {X=*((int*)pstr);pstr+=sizeof(int);}
#define UNPACK_INT64(X)           {X=*((__int64*)pstr);pstr+=sizeof(__int64);}
#define UNPACK_SHORT(X)           {X=*((short*)pstr);pstr+=sizeof(short);}
#define UNPACK_LONG(X)            {X=*((long*)pstr);pstr+=sizeof(long);}
#define UNPACK_CHAR(X)            {X=*((char*)pstr);pstr+=sizeof(char);}
#define UNPACK_UINT(X)            {X=*((unsigned int*)pstr);pstr+=sizeof(unsigned int);}
#define UNPACK_USHORT(X)          {X=*((unsigned short*)pstr);pstr+=sizeof(unsigned short);}
#define UNPACK_ULONG(X)           {X=*((unsigned long*)pstr);pstr+=sizeof(unsigned long);}
#define UNPACK_UCHAR(X)           {X=*((unsigned char*)pstr);pstr+=sizeof(unsigned char);}
#define UNPACK_STRING(X)          {size_t str_size=0;UNPACK_UINT(str_size);X.append(pstr, str_size);pstr+=str_size;}
#define UNPACK_STRING_RAW(X)      {const char * pstrend=src.c_str()+src.size();X.append(pstr, pstrend-pstr);pstr=pstrend;}
#define UNPACK_DOUBLE(X)          {X=*((double*)pstr);pstr+=sizeof(double);}
#define UNPACK_FLOAT(X)           {X=*((float*)pstr);pstr+=sizeof(float);}
#define UNPACK_CLASS(X)           {string src_t;src_t.append(pstr,src.size()-(pstr-src.c_str()));const char* pstr_t=X.toObject(src_t);pstr+=pstr_t-src_t.c_str();}
#define UNPACK_CLASS_ARRAY(X, N)  {size_t array_size=0;UNPACK_UINT(array_size);for(int i=0;i<array_size;i++){UNPACK_CLASS(X[i]);}}
#define UNPACK_STRING_ARRAY(X, N) {size_t array_size=0;UNPACK_UINT(array_size);for(int i=0;i<array_size;i++){UNPACK_STRING(X[i]);}}
#define UNPACK_DOUBLE_ARRAY(X, N) {size_t array_size=0;UNPACK_UINT(array_size);for(int i=0;i<array_size;i++){UNPACK_DOUBLE(X[i]);}}
#define UNPACK_ULONG_VECTOR(X)    {size_t array_size=0;UNPACK_UINT(array_size);X.resize(array_size);for(int i=0;i<array_size;i++){UNPACK_ULONG(X.at(i));}}
#define UNPACK_UINT_VECTOR(X)     {size_t array_size=0;UNPACK_UINT(array_size);X.resize(array_size);for(int i=0;i<array_size;i++){UNPACK_UINT(X.at(i));}}
#define UNPACK_UCHAR_VECTOR(X)    {size_t array_size=0;UNPACK_UINT(array_size);X.resize(array_size);for(int i=0;i<array_size;i++){UNPACK_UCHAR(X.at(i));}}
#define UNPACK_CLASS_VECTOR(X)    {size_t array_size=0;UNPACK_UINT(array_size);X.resize(array_size);for(int i=0;i<array_size;i++){UNPACK_CLASS(X.at(i));}}
#define UNPACK_UINT_ARRAY(X, N)   {size_t array_size=0;UNPACK_UINT(array_size);for(int i=0;i<array_size;i++){UNPACK_UINT(X[i]);}}
#define UNPACK_USHORT_ARRAY(X, N) {size_t array_size=0;UNPACK_USHORT(array_size);for(int i=0;i<array_size;i++){UNPACK_USHORT(X[i]);}}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//字符串编解码使用实例
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//自定义消息类
// class MsgTest
// {
// public:
// 	//消息内容定义区
// 	unsigned short usMsgID;//消息ID
// 	string strMsgContent;//消息内容
// 	
// public:
// 	//消息内容编码区
// 	virtual string toString() const
// 	{
// 		string ret;
// 		PACK_USHORT(usMsgID);
// 		PACK_STRING(strMsgContent);
// 		return ret;
// 	}
// 	//消息内容解码区
// 	virtual const char * toObject(const string src)
// 	{
// 		const char * pstr = src.c_str();
// 		UNPACK_USHORT(usMsgID);
// 		UNPACK_STRING(strMsgContent);
// 		return pstr;
// 	}
// };

//自定义消息类与字符串的相互转换
// MsgTest msg;//自定义消息类
// string strContent;//编码后的字符串
// 
// strContent = msg.toString(); //自定义消息类->字符串	
// msg.toObject(strContent);//字符串->自定义消息类	
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_CODETRANSLATOR_H_
