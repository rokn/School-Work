require 'csv'

arr1 = []

CSV.open("result.csv", "w") do |csv|
  Dir.glob(ARGV[0] + "*").each do |filename|
    name = filename.split("/").last.split("_")
    if name[0].size == 5
      arr1 << name
    end
  end

  Dir.glob(ARGV[1] + "*").each do |filename|
    name = filename.split("/").last.split("_") 
    if name[0].size == 5
        if arr1.include?(name)
            csv << [name[1],name[0]]
        end
    end
  end
end

def sort_result
    my_csv = CSV.read 'result.csv'
    my_csv.sort! { |a,b| a[0].downcase <=> b[0].downcase}
    CSV.open("result.csv", "w") do |csv|
      my_csv.each {|element| csv << element}
    end
end
