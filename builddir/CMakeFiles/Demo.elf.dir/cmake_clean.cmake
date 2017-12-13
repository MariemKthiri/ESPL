FILE(REMOVE_RECURSE
  "Demo.elf.pdb"
  "Demo.elf"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/Demo.elf.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
