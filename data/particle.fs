#version 330

uniform sampler2D texture;
uniform vec4 part_colour;

in vec2 tex_coord;

in FS {
    in float dist;
    in float ttl;
};

out vec4 colour;

void main() {
    vec4 tex = texture2D(texture, tex_coord);
    colour = vec4(mix(tex.rgb, part_colour.rgb, tex.rgb), tex.a);
}
