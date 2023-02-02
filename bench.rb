ruby_bin_path = "~/.rubies/mvh-declarative-marking/bin/ruby"
RUNS = 50

output = []
RUNS.times do
  simp_stat = eval(`#{ruby_bin_path} test_simple_marking.rb`)
  decl_stat = eval(`#{ruby_bin_path} test_decl_marking.rb`)

  output << {simp: simp_stat.fetch(:time), decl_time: decl_stat.fetch(:time)}
end

require 'csv'

columns = output.first.keys
outdata = CSV.generate do |csv|
  csv << columns
  output.each do |row|
    csv << row.values
  end
end

File.write("output.csv", outdata)


