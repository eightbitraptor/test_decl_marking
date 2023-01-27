# Test declarative marking

This repo contains a C extension and a ruby script that exists only for the
purposes of testing a Ruby feature I'm exloring.

1. clone `shopify/ruby` and checkout `mvh-declarative-marking`
2. build and install Ruby
3. switch to that ruby using `$VERSION_MANAGER`
4. clone this repo somewhere
5. `cd $repo_location/ext && ruby extconf.rb && make`
6. `cd ..`
7. `ruby bench.rb`
