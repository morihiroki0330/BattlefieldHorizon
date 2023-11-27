 cbuffer ModelCb : register(b0)
{
	float4x4 mWorld;
	float4x4 mView;
	float4x4 mProj;
};

struct SVSIn 
{
	float4 pos 		: POSITION;	
	float3 normal   :NORMAL;
	float2 uv 		: TEXCOORD0;	
	float3 tangent  : TANGENT;
	float3 biNormal : BINORMAL;
};

struct SPSIn 
{
	float4 pos 			: SV_POSITION;	
	float3 normal       :NORMAL;
	float2 uv 			: TEXCOORD0;	
	float3 worldPos     : TEXCOORD1;
	float3 normalInView : TEXCOORD2;
	float3 tangent  : TANGENT;
	float3 biNormal : BINORMAL;
	float4 color : COLOR;
};

struct PixelInput
{
    float4 position : SV_POSITION;
    float2 TexCoord : TEXCOORD;
};

Texture2D<float4> g_albedo : register(t0);				
Texture2D<float4> g_normalMap : register(t1);				
Texture2D<float4> g_specularMap : register(t2); 

Texture2D<float4> g_GrassMap : register(t10);
Texture2D<float4> g_SoilMap : register(t11);
Texture2D<float4> g_TextureMap : register(t12);
Texture2D<float4> g_HeightMap : register(t13);

sampler g_sampler : register(s0);	

SPSIn Format(SVSIn vsIn)
{
	SPSIn psIn;
	psIn.uv = vsIn.uv;

	float4 Height = g_HeightMap.Sample(g_sampler,vsIn.uv);

	psIn.worldPos = vsIn.pos;

	psIn.pos = mul(mWorld, vsIn.pos);
	psIn.pos = mul(mView, psIn.pos);
	psIn.pos = mul(mProj, psIn.pos);

	psIn.normal = mul(mWorld, vsIn.normal);
	psIn.normalInView = mul(mView, psIn.normal);
	psIn.tangent = normalize(mul(mWorld, vsIn.tangent));
	psIn.biNormal = normalize(mul(mWorld, vsIn.biNormal));
	return psIn;
}

SPSIn VSMain(SVSIn vsIn)
{
	SPSIn psIn;
	psIn = Format(vsIn);
	return psIn;
}

float4 PSMain(SPSIn psIn,PixelInput piIn) : SV_Target0
{
	float4 TexColor = g_TextureMap.Sample(g_sampler,psIn.uv);

    if(TexColor.r>TexColor.g)
	{
		if(TexColor.r>TexColor.b)
		{
			TexColor = g_SoilMap.Sample(g_sampler,psIn.uv);
			TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
		}
	}else{
		if(TexColor.g>TexColor.r)
		{
			if(TexColor.g>TexColor.b)
			{
				TexColor = g_GrassMap.Sample(g_sampler,psIn.uv);
				TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
			}
	}else{
			if(TexColor.b>TexColor.g)
			{
				if(TexColor.b>TexColor.r)
				{
					TexColor = g_SoilMap.Sample(g_sampler,psIn.uv);
					TexColor.rgb = pow(TexColor.rgb, 1.0 / 2.2);
				}
			}
		}
	}
	return TexColor;
}
