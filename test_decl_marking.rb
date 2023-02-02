require_relative "ext/test_decl_marking"
GC.disable
OBJ_COUNT = 500_000

def create_decl_objects
  $list = []
  OBJ_COUNT.times do
    $list << DeclMarking.new
  end
end

create_decl_objects
GC.compact
puts GC.stat
