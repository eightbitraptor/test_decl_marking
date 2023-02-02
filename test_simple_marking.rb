require_relative "ext/test_decl_marking"
GC.disable
OBJ_COUNT = 500_000

def create_simple_objects
  $list = []
  OBJ_COUNT.times do
    $list << SimpleMarking.new
  end
end

create_simple_objects
GC.compact
puts GC.stat
