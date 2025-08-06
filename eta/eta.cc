#include "eta.h"
#include <algorithm>
#include <cassert>

eta::eta(CACHE* cache) : eta(cache, cache->NUM_SET, cache->NUM_WAY) {}

eta::eta(CACHE* cache, long sets, long ways)
    : replacement(cache), NUM_WAY(ways), eta_value(static_cast<std::size_t>(sets * ways), 0) {}

long eta::find_victim(uint32_t triggering_cpu, uint64_t instr_id, long set, const champsim::cache_block* current_set, champsim::address ip,
                      champsim::address full_addr, access_type type) {
  auto begin = std::next(eta_value.begin(), set * NUM_WAY);
  auto end = std::next(begin, NUM_WAY);
  auto victim = std::max_element(begin, end);

  assert(begin <= victim && victim < end);
  return std::distance(begin, victim);
}

void eta::replacement_cache_fill(uint32_t triggering_cpu, long set, long way, champsim::address full_addr, champsim::address ip, champsim::address victim_addr,
                                 access_type type) {
 uint64_t full_addr_val = full_addr.to<uint64_t>();
 uint64_t predicted_reuse = (full_addr_val % 1000) + 100;
 eta_value.at(set * NUM_WAY + way) = current_time + predicted_reuse;
 current_time++;
}

void eta::update_replacement_state(uint32_t triggering_cpu, long set, long way, champsim::address full_addr, champsim::address ip,
                                   champsim::address victim_addr, access_type type, uint8_t hit) {
  if (hit) {
    uint64_t full_addr_val = full_addr.to<uint64_t>();
    eta_value.at(set * NUM_WAY + way) = current_time + ((full_addr_val % 1000) + 100);
  } 
  current_time++;
}
