#extension GL_ARB_texture_rectangle : enable

uniform vec3 iResolution;
uniform vec3 iChannelResolution;
uniform sampler2DRect image;
uniform sampler2DRect bump;

void main(void) {
	float zr = 1.0-texture2DRect( image, gl_TexCoord[0].xy ).x;
	float ao = 0.0;
	for( int i=0; i<8; i++ ) {
            vec2 off = -1.0 + 2.0*texture2DRect( bump, (gl_TexCoord[0].xy + 23.71*float(i)) ).xz;
            float z = 1.0-texture2DRect( image, (gl_TexCoord[0].xy + floor(off*16.0)) ).x;
            ao += clamp( (zr-z)/0.1, 0.0, 1.0);
	}
        ao = clamp( 1.0 - ao/8.0, 0.0, 1.0 );
	vec3 col = vec3(ao);
        //        col *= texture2DRect( image, gl_TexCoord[0].xy ).xyz;/*buffer color image*/
	gl_FragColor = vec4(col,1.0);
}
