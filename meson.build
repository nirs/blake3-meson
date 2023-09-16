project(
  'blake3-meson', 'c',
  default_options: [
    'buildtype=release',
  ]
)

blake3_dep = dependency('blake3', fallback : ['blake3', 'blake3_dep'])

executable('example', 'example.c', dependencies : blake3_dep)
