#include <iostream>
#include <memory>
class Investment {
public:
  Investment() {}
  virtual ~Investment() {}
  static Investment *CreateInvestment(int type);
  virtual void Print() = 0;
};

class YaWenInvestment : public Investment {

public:
  YaWenInvestment() {}
  ~YaWenInvestment() {}
  void AddYaWenInvestment(const int n) { money_ += n; }
  void Print() { std::cout << "Yawen's money:гд" << money_ << ".00" << std::endl; }

private:
  static int money_;
};

int YaWenInvestment::money_;

Investment *Investment::CreateInvestment(int type) {
  switch (type) {
  case 1:
    return new YaWenInvestment;
  default:
    break;
  }
  return nullptr;
}
int main() {
  std::cout << "Item 13: Use objects to manage resources." << std::endl;

  {
    /*
    auto pInv = std::make_shared<Investment>();
    std::cout
        << "size: " << sizeof(pInv)
        << std::endl; // Do you know why the size is 16 bytes on 64bit system.
    auto p = (YaWenInvestment *)pInv->CreateInvestment(1);
    p->AddYaWenInvestment(100);
    delete p;
    */
  }

  {
    std::auto_ptr<YaWenInvestment> pInv1(
        (YaWenInvestment *)Investment::CreateInvestment(1));
    std::cout << "pInv1 point to: " << pInv1.get() << std::endl;
    std::auto_ptr<YaWenInvestment> pInv2(pInv1);
    std::cout << "pInv1 point to: " << pInv1.get()
              << std::endl;
    std::cout << "pInv2 point to: " << pInv2.get() << std::endl;
    pInv2->AddYaWenInvestment(1000000);
    pInv1 = pInv2;
  }

  {
    std::shared_ptr<YaWenInvestment> pInv3(
        (YaWenInvestment *)Investment::CreateInvestment(1));
    std::cout << "shared_ptr pInv3 point to: " << pInv3.get() << std::endl;
    std::shared_ptr<YaWenInvestment> pInv4(pInv3);
    std::cout << "shared_ptr pInv3 point to: " << pInv3.get() << std::endl;
    pInv4->AddYaWenInvestment(1000000);
    pInv4->Print();
    std::cout << "shared_ptr pInv4 point to: " << pInv4.get() << std::endl;
  }

  return 0;
}