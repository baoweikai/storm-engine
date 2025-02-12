technique RandItem
{
    pass p0
    {
        Lighting = true;
        CullMode = CW;
        AlphaTestEnable = true;
        AlphaBlendEnable = true;
        SrcBlend = srcalpha;
        DestBlend = invsrcalpha;

        ColorOp[0] = modulate2x;
        ColorArg1[0] = texture;
        ColorArg2[0] = current;

        AlphaOp[0] = SelectArg1;
        AlphaArg1[0] = texture;

        ColorOp[1] = disable;
    }
}