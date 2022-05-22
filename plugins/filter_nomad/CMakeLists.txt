set(src
  nomad_conf.c
  nomad_meta.c
  nomad_regex.c
  nomad_property.c
  nomad.c
  )

FLB_PLUGIN(filter_nomad "${src}" "")

# K8s token command is currently Linux-only.
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  FLB_DEFINITION(FLB_HAVE_NOMAD_TOKEN_COMMAND)
endif()