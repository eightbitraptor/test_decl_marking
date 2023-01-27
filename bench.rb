require 'benchmark'

ruby_bin_path = "~/.rubies/mvh-declarative-marking/bin/ruby"

Benchmark.bm do |x|
  x.report("Simple") { system("#{ruby_bin_path} test_simple_marking.rb") }
  x.report("Decl") { system("#{ruby_bin_path} test_decl_marking.rb") }
end
