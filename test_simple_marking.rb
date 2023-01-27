require_relative "ext/test_decl_marking"
GC.disable
OBJ_COUNT = 2_500_000

def create_simple_objects
  $list = []
  OBJ_COUNT.times do
    $list << SimpleMarking.new
  end
end

create_simple_objects
GC.verify_compaction_references(toward: :empty, expand_heap: true)
