#pragma once
#include <wrl.h>
#include <string>
#include <dxcapi.h>

// 共通
class SpriteCommon
{
public:
	// 初期化
	void Initialize();

private:
	static IDxcBlob* CompileShader(
		// CompilerするShaderファイルパス
		const std::wstring& filePath,
		// Compilerに使用するProfile
		const wchar_t* profile,
		// DXC
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
		);
};