# CMake Modules for RemoteAdmin

This directory contains CMake modules copied from the RTI Connext DDS CMake Utilities repository for convenience. These modules are included locally to avoid requiring users to initialize git submodules.

## Files Included

- **ConnextDdsCodegen.cmake** - Module for running rtiddsgen code generation
- **ConnextDdsArgumentChecks.cmake** - Utility module for argument validation (required by ConnextDdsCodegen)
- **FindRTIConnextDDS.cmake** - Module for finding RTI Connext DDS installation

## Source

These files are from the [rticonnextdds-cmake-utils](https://github.com/rticommunity/rticonnextdds-cmake-utils) repository, specifically from the `cmake/Modules/` directory.

## Updates

If RTI Connext DDS CMake utilities are updated, these files may need to be refreshed. To update:

```bash
# Copy latest versions from the submodule at repository root
cp ../../resources/rticonnextdds-cmake-utils/cmake/Modules/ConnextDdsCodegen.cmake ./
cp ../../resources/rticonnextdds-cmake-utils/cmake/Modules/ConnextDdsArgumentChecks.cmake ./
cp ../../resources/rticonnextdds-cmake-utils/cmake/Modules/FindRTIConnextDDS.cmake ./
```

## License

These cmake modules are provided by RTI and subject to the same license as RTI Connext DDS.
