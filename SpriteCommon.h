#pragma once
#include <wrl.h>
#include <string>
#include <dxcapi.h>

// ����
class SpriteCommon
{
public:
	// ������
	void Initialize();

private:
	static IDxcBlob* CompileShader(
		// Compiler����Shader�t�@�C���p�X
		const std::wstring& filePath,
		// Compiler�Ɏg�p����Profile
		const wchar_t* profile,
		// DXC
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
		);
};