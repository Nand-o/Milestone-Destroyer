project(
  'Milestone Destroyer',
  'cpp',
  version : '0.1',
  meson_version : '>= 1.3.0',
  default_options : ['warning_level=3', 'cpp_std=c++14'],
)

# Cari dependensi Boost Serialization
boost_dep = dependency('boost', modules : ['serialization'], required : true)

# Daftar source files
sources = [
  'main.cpp',
  'handlers.cpp',
  'user.cpp'
]

# (Opsional) Jika player_data.hpp ada di subfolder 'include'
# inc_dirs = [include_directories('include')]

# Definisi executable
executable('milestone', # Nama file output
  sources,
  # include_directories : inc_dirs, # Gunakan jika ada subfolder include
  dependencies : [boost_dep] # Tautkan dengan Boost Serialization
)
